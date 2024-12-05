#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#define DEVICE_PATH "/dev/simple_device"  // The path to the device

struct logs {
    char msg[100];  // Buffer to store log message
};

int main() {
    struct logs svar[5];      // Array to hold up to 5 logs
    int fd = open(DEVICE_PATH, O_RDWR);  // Open the device file for read and write
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    int i = 0;  // Index to cycle through the messages
    char str[100], res[500];  // Buffer to write and read messages

    while (1) {
        printf("Enter message: ");
        // Get input from user and remove newline character
        scanf(" %[^\n]s", svar[i].msg);  // Read the message into the log buffer
        sprintf(str, "%s", svar[i].msg);  // Copy the message to a temporary buffer
        
        // Write the message to the device
        int w = write(fd, str, strlen(str));
        if (w == -1) {
            perror("write failed");
        } 
        // Read from the device (circular buffer) to get logs
        int r = read(fd, res, sizeof(res)-1);  // Read up to 500 bytes (for multiple logs)
        if (r == -1) {
            perror("read failed");
        }else{
            res[r] = '\0';  // Null-terminate the response string
            printf("Logs from kernel:\n%s", res);  // Print the logs
	}
        i = (i + 1) % 5;  // Update index to cycle through logs (0-4)
        sleep(2);  // Delay to give time for device interaction (optional)
    }

    close(fd);  // Close the device when done
    return 0;
}

