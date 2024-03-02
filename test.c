#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char auth_file[500]="data/auth.csv";
// validate user credentials
int authenticateUser(int userType, const char *username, const char *password) {
    FILE *file = fopen(auth_file, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int storedUserType;
        char storedUsername[50];
        char storedPassword[50];
        char storedEmail[50];

        sscanf(line, "%d,%[^,],%[^,],%s", &storedUserType, storedUsername, storedPassword, storedEmail);

        if (userType == storedUserType && strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            fclose(file);
            return 1; // Authentication successful
        }
    }

    fclose(file);
    return 0; // Authentication failed
}

// Function to reset the password
void resetPassword(const char *username) {
    char newPassword[50];

    printf("Enter a new password for %s: ", username);
    scanf("%s", newPassword);

    FILE *file = fopen(auth_file, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    FILE *tempFile = fopen("temp_users.csv", "w");
    if (tempFile == NULL) {
        printf("Error opening the file.\n");
        fclose(file);
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char storedUsername[50];
        char storedPassword[50];
        char storedEmail[100];

        sscanf(line, "%*d,%[^,],%*[^,],%[^,]", storedUsername, storedEmail);

        if (strcmp(username, storedUsername) == 0) {
            fprintf(tempFile, "0,%s,%s,%s\n", storedUsername, newPassword, storedEmail);
        } else {
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(auth_file);
    rename("temp_users.csv", auth_file);
    remove("temp_users.csv");

    printf("Password reset successfully.\n");
}

// Function to add a new user (for user type 0)
void addUser() {
    char newUserType[2];
    char newUsername[50];
    char newPassword[50];
    char newSecurity[50];

    printf("Enter the user type (0, 1, or 2) for the new user: ");
    scanf("%s", newUserType);

    printf("Enter the username for the new user: ");
    scanf("%s", newUsername);

    printf("Enter the password for the new user: ");
    scanf("%s", newPassword);

    printf("Enter the email address for the new user: ");
    scanf("%s", newEmail);

    FILE *file = fopen(auth_file, "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    fprintf(file, "%s,%s,%s,%s\n", newUserType, newUsername, newPassword, newEmail);
    fclose(file);

    printf("New user added successfully.\n");
}

int main() {
    int choice;
    int userType;
    char username[50];
    char password[50];

    printf("1. Login\n");
    printf("2. Forget Password\n");
    printf("3. Add New User (Admin Only)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter user type (0, 1, or 2): ");
        scanf("%d", &userType);

        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        if (authenticateUser(userType, username, password)) {
            printf("Authentication successful.\n");
        } else {
            printf("Authentication failed.\n");
        }
    } else if (choice == 2) {
        printf("Enter your username to reset the password: ");
        scanf("%s", username);

        resetPassword(username);
    } else if (choice == 3) {
        printf("You selected 'Add New User.'\n");
        addUser();
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

