# Newsletter
- Description
    - The purpose of our project is to find out how to
    use an Application Programming Interface (API) to
    access information from a website and send that
    information to a user email. In this project, we get
    the top 10 news highlights of the day and send it
    to our clients via email every morning. We created
    this project in order to make it easier to notify
    users about current news without them having to
    search for news separately on google or any other
    site. Some of the technical challenges include
    having to only use Python to create our program
    while using multiple APIs. There is also a technical
    challenge of establishing a socket connection on a
    server/client program in order to send information
    to an email, and if the socket connection fails, the
    program will not work.

**Libraries**
- gspread
    - pip install gspread
- requests
    - already in the python library
- json
    - already in the python library
- sendgrid
    - echo "export SENDGRID_API_KEY='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'" > sendgrid.env
    - echo "sendgrid.env" >> .gitignore
    - source ./sendgrid.env
    - pip install sendgrid
- gmail to send emails
    - dailynewsletter@gmail.com
    - pw: dailynewsletter
    - Client database: in google sheet, named Client

**Instructions**
- in terminal type
    - pip install gspread
    - echo "export SENDGRID_API_KEY='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'" > sendgrid.env
    - echo "sendgrid.env" >> .gitignore
    - source ./sendgrid.env
    - pip install sendgrid
    - python main.py
