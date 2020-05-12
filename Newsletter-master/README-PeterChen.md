# Newsletter

**Peter Chen**
- set up new gamil account for this project
- authentication.py
    - authenticate(): a method to authenticate the credential file got from google api, which gave us access to Google sheet API and Google Drive API
- manageData.py
    - This file basically contains methods to communicate with google sheets through google sheet API
    - getlist(): This function allows us to get information from specific column from the google sheets
    - writelist(): This function allows us to write a list to the google sheets to a specific column
    - emailInput(): Will let the user to input email then store them into a google sheet
- news.py
    - This method would get top 20 trend news from news api and get it ready to send to our clients
    - Since there is no Google News Api, we found another news api, which basically can do the same thing
    - api.txt
    - I put the api key in this file, so the api key won't appear on Github, which would prevent the api leaking
    - This program would grab top trend news(around 20 news) from all the sources, including BBC, The New York Times, The Los Angeles Times and so on, and output their title and the links to the article
- send_email.py
    - This method would send emails to our clients in our database using sendgrid API
    - Need to set up the environemnt first
        - echo "export SENDGRID_API_KEY='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'" > sendgrid.env
        - echo "sendgrid.env" >> .gitignore
        - source ./sendgrid.env
        - pip install sendgrid
    - Using SendGrid's API to send emails
    - sendEmail(email, message)
        - Emails will be sent from dailynewsletter@gmail.com
- main.py
    - This is the program itself, it wouls ask users for email input then send top trend news to all the clients in the database