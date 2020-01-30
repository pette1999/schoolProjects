from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup as soup
from urllib.request import urlopen as uReq
import os
import ssl
import time

# html = browser.page_source

# d = open("out.txt", "w")
# d.write(html)
# d.close()

# browser.find_element_by_id('ln').send_keys('WHAT')
# elements = browser.find_elements_by_xpath("//*[contains(text(), 'name')]")
# for i in elements:
#     print(i.get_attribute())


my_url = 'https://www.superiorcourt.maricopa.gov/docket/CriminalCourtCases/caseSearch.asp'

if (not os.environ.get('PYTHONHTTPSVERIFY', '') and getattr(ssl, '_create_unverified_context', None)):
    ssl._create_default_https_context = ssl._create_unverified_context

# opening up connection, grabbing the page
uClient = uReq(my_url)

page_html = uClient.read()
uClient.close()

# html_parsing
page_soup = soup(page_html, "html.parser")

# print(page_soup)
# find all input boxes on the page
inputs = page_soup.findAll('input', {'type': 'text'})

first_possibilities = ["fn", "firstname", "first", "fname"]
last_possibilities = ["ln", "lastname", "last", "lname"]
first_name = []
last_name = []
has_id = False # boolean to determine if has id
has_name = False # boolean to determine if has name
for i in inputs:
    print(i.get('id'))
for i in inputs:
    print(i.get('id'))

for i in inputs:
    try:
        for j in first_possibilities:
            if(j in i.get('id').lower()):
                first_id = i.get('id')
                has_id = True
            else:
                pass
    except:
        print("Missing firstname id")
        has_id = False

    try:
        for k in last_possibilities:
            if(k in i.get('id').lower()):
                last_id = i.get('id')
                has_id = True
    except:
        print("Missing lastname id")
        has_id = False

    try:
        for a in first_possibilities:
            if(a in i.get('name').lower()):
                first_name.append(i.get('name'))
                print(first_name)
                has_name = True
            else:
                pass
    except:
        print("Missing firstname name")
        has_name = False

    try:
        for b in last_possibilities:
            if(b in i.get('name').lower()):
                last_name.append(i.get('name'))
                print(last_name)
                has_name = True
            else:
                pass
    except:
        print("Missing lastname name")
        has_name = False

button = page_soup.findAll('input', {'type': 'submit'})

for i in button:
    print(type(i))

button_id = button[0].get('id')

# selenium
browser = webdriver.Chrome()
browser.get(my_url)

if(has_id):
    print("Using id.")
    element = browser.find_element_by_id(first_id)
    element.send_keys('john')
    element = browser.find_element_by_id(last_id)
    element.send_keys('miller')
    currentUrl = browser.current_url
    element.send_keys(Keys.RETURN)
    # need to check if the button has an id
    if(browser.current_url == currentUrl):
        element = browser.find_element_by_id(button_id)
        element.click()
elif(has_name):
    print("Using name.")
    element = browser.find_element_by_name(first_name[0])
    element.send_keys('john')
    element = browser.find_element_by_name(last_name[0])
    element.send_keys('miller')
    currentUrl = browser.current_url
    element.send_keys(Keys.RETURN)
    if(browser.current_url == currentUrl):
        element = browser.find_element_by_id(button_id)
        element.click()

my_url = browser.current_url
uClient = uReq(my_url)

page_html = uClient.read()
uClient.close()
page_soup = soup(page_html, "html.parser")
case_link = []
for a in page_soup.findAll('a', href=True):
    if('caseNumber' in a['href']):
        case_link.append(a['href'])


# Go through the cases and take screenshots
current_url = 'http://www.superiorcourt.maricopa.gov/' + case_link[0]
# print(current_url)
browser.get(current_url)
str1 = ""
str2 = ""
x = browser.get_window_size()
y = browser.execute_script("return document.documentElement.scrollHeight")
count = 1
for i in range(x['height'], y, x['height']):
            str1 = "window.scrollTo(0, " + str(i) + ");"
            browser.execute_script(str1)
            str2 = "court_screenshot_" + str(count) + ".png"
            browser.save_screenshot(str2)
            count += 1
            time.sleep(3)

