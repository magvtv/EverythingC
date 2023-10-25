#!/bin/bash

csv_file="recipients.csv"

if [ ! -f "$csv_file" ]; then
    echo "CSV file not found."
    exit 1
fi

invitation_content=$(<invitation.txt)


while IFS=, read -r name email; do

    temp_email="invitation_${name// /_}.txt"
    echo "Subject: Invitation to 3rd Year Projects Webinar" > "$temp_email"
    echo "To: $email" >> "$temp_email"
    echo "" >> "$temp_email"
    echo "$invitation_content" >> "$temp_email"

    # Send the email using mutt
    # mutt -s "Invitation to 3rd Year Projects Webinar" "$email" < "$temp_email"


    rm "$temp_email"
done < "$csv_file"
