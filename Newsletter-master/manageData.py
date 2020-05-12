import gspread
import authentication

# This method would get list from preset google sheet named "Clients" in account dailynewsletter@gmail.com
def getList():
    json_file_name = 'daily-newsletter-3f8ed4c4331e.json'
    credential = authentication.authenticate(json_file_name)
    gc = gspread.authorize(credential)

    # open the google sheet
    wks = gc.open("Clients").sheet1

    # get list from the first column
    values_list = wks.col_values(1)
    return values_list


# this method would write emails to the first column
# takes in a string as argument for email inputs and a list as an argument for existing list, so we can know where to put the next next email
def writeList(value_list, value):
    json_file_name = 'daily-newsletter-3f8ed4c4331e.json'
    credential = authentication.authenticate(json_file_name)
    gc = gspread.authorize(credential)
    wks = gc.open("Clients").sheet1

    wks.update_cell(len(value_list)+1, 1, value)

# this method would ask users for input
def emailInput():
    email = input("Please input your email here: ")
    writeList(getList(), email)
