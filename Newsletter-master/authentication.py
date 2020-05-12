from oauth2client.service_account import ServiceAccountCredentials

# this method will authenticate the credential file and give access to google sheets/drive
def authenticate(json_name):
    scope = ['https://spreadsheets.google.com/feeds', 'https://www.googleapis.com/auth/drive']
    credentials = ServiceAccountCredentials.from_json_keyfile_name(json_name, scope)
    return credentials


