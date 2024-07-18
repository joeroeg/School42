#!/bin/bash

env_file="srcs/.env"

# Check if .env file exists
if [ -e "$env_file" ]; then
    echo ".env file already exists."
    exit 1
fi

# Function to validate input (no 'admin' allowed)
validate_input() {
    local input=$1
    if [[ "$input" =~ admin ]]; then
        echo "Error: Usernames/passwords cannot contain 'admin'."
        return 1
    fi
    return 0
}

# Function to prompt user for sensitive input
prompt_input() {
    local prompt_message="$1"
    local var_name="$2"
    while true; do
        read -p "$prompt_message: " "$var_name"
        echo
        if ! validate_input "${!var_name}"; then
            continue
        fi
        read -p "$prompt_message (confirm): " confirm_value
        echo
        if [ "${!var_name}" == "$confirm_value" ]; then
            break
        else
            echo "Error: Values do not match. Please try again."
        fi
    done
}

# Prompt user for input variables
prompt_input "Enter the domain name" "DOMAIN_NAME"

prompt_input "Enter the MySQL root password" "MYSQL_ROOT_PASSWORD"
prompt_input "Enter the MySQL database name" "MYSQL_DATABASE"
prompt_input "Enter the MySQL username" "MYSQL_USER"
prompt_input "Enter the MySQL password" "MYSQL_PASSWORD"

prompt_input "Enter the WordPress site title" "WP_TITLE"
prompt_input "Enter the WordPress admin username" "WP_ADMIN"
prompt_input "Enter the WordPress admin password" "WP_PASSWORD"
prompt_input "Enter the WordPress admin email" "WP_EMAIL"
prompt_input "Enter the WordPress user username" "WP_USER"
prompt_input "Enter the WordPress user email" "WP_USER_EMAIL"
prompt_input "Enter the WordPress user password" "WP_USER_PASSWORD"


# Write variables to .env file
cat <<EOF > "$env_file"
DOMAIN_NAME=$DOMAIN_NAME

MYSQL_ROOT_PASSWORD=$MYSQL_ROOT_PASSWORD
MYSQL_DATABASE=$MYSQL_DATABASE
MYSQL_USER=$MYSQL_USER
MYSQL_PASSWORD=$MYSQL_PASSWORD

WP_TITLE=$WP_TITLE
WP_ADMIN=$WP_ADMIN
WP_PASSWORD=$WP_PASSWORD
WP_EMAIL=$WP_EMAIL
WP_USER=$WP_USER
WP_USER_EMAIL=$WP_USER_EMAIL
WP_USER_PASSWORD=$WP_USER_PASSWORD
EOF

echo ".env file created successfully."
