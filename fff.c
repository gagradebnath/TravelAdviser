#include <stdlib.h>
#include <stdio.h>

void run_python(){
	// Command to be executed
    char command[] = "python ai.py";

    // Execute the command
    int result = system(command);

    if (result == -1) {
        perror("Error executing command");
    }
	else{
		printf("python executed\n");
	}

}

int main() {
    run_python();

    return 0;
}
