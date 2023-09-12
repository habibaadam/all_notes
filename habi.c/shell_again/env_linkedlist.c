#include "shell.h"

int custom_setenv(const char* name, const char* value, int overwrite)
{
     Node* current;
     Node* new_var;
     if (name == NULL || value == NULL) {
        return -1; 
    }

    current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (overwrite == 0) {
                return 0; 
            } else {
              
                free(current->value);
                current->value = strdup(value);
                if (current->value == NULL) {
                    perror("Memory allocation error");
                    return -1; 
                }
                return 0;
            }
        }
        current = current->next;
    }
    new_
      var = (Node*)malloc(sizeof(Node));
    if (new_var == NULL) {
        perror("Memory allocation error");
        return -1; 
    }

    new_var->name = strdup(name);
    new_var->value = strdup(value);
    if (new_var->name == NULL || new_var->value == NULL) {
        free(new_var->name);
        free(new_var->value);
        free(new_var);
        perror("Memory allocation error");
        return -1; // Memory allocation failed
    }

    // Add the new node to the beginning of the linked list
    new_var->next = head;
    head = new_var;

    return 0;
}

int custom_unsetenv(const char* name)
{
     Node* current;
     Node* prev;
     if (name == NULL) {
        return -1; // Invalid input
    }

    current = head;
    prev = NULL;

    // Find the node with the given name in the linked list
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // Remove the node from the linked list
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }

            // Free memory occupied by the node and its contents
            free(current->name);
            free(current->value);
            free(current);

            return 0;
        }

        prev = current;
        current = current->next;
    }

    return 0; // Variable not found, but we return 0 to mimic the behavior of unsetenv
}

void write_environment_variables() 
{
    Node* current = head;
    char buffer[100];

    while (current != NULL) {
        // Create a formatted string in the format "name=value"
        snprintf(buffer, sizeof(buffer), "%s=%s\n", current->name, current->value);

        // Write the string to the standard output using the write system call
        write(STDOUT_FILENO, buffer, strlen(buffer));

        current = current->next;
    }
}

void free_linked_list()
{
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->name);
        free(temp->value);
        free(temp);
}
}
