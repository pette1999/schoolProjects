# using SendGrid's Python Library
# https://github.com/sendgrid/sendgrid-python
import os
from sendgrid import SendGridAPIClient
from sendgrid.helpers.mail import Mail

# this method would allow us to send emails
# takes in an email address as an argument and message as an argument for email content
def sendEmail(email, message):
    message = Mail(
        from_email='yourdailynewsletter@gmail.com',
        to_emails=email,
        subject='Your Daily Newsletter',
        html_content="<h2>Daily Newsletter</h2>" + message)
    try:
        sg = SendGridAPIClient(os.environ.get('SENDGRID_API_KEY'))
        response = sg.send(message)
        # print(response.status_code)
        # print(response.body)
        # print(response.headers)
    except Exception as e:
        print(e.message)