graph TD
    A[Start] --> B[Open auth_file]
    B --> C{file == NULL?}
    C -->|Yes| D[Error opening file<br>Return 0]
    C -->|No| E[Read line from file]
    E --> F{End of file?}
    F -->|Yes| G[Return 0<br>Authentication failed]
    F -->|No| H[Parse line]
    H --> I{Check userType,<br>username, password}
    I -->|Yes| J[Close file<br>Return 1<br>Authentication successful]
    I -->|No| E
