import requests
import json

def getNews():

    # Stored the api key in a seperate file and read it through the file
    # To protect the api key from leaking
    f = open("api.txt", "r")
    api = f.readline().strip()
    print("api: ", api)

    url = ('http://newsapi.org/v2/top-headlines?' + 'country=us&' + api)
    top_headlines = requests.get(url).json()
    articles = top_headlines["articles"]

    count = 0
    # empty list which will
    # contain all trending news
    results = []
    urls = []
    for article in articles:
        results.append(article["title"])
        urls.append(article["url"])

    # put all information we got from the api into a text
    text = ""
    for i in range(len(results)):
        # printing all trending news
        print(i + 1, results[i])
        print(urls[i])
        text += "<p>"
        text += str(i+1)
        text += "  "
        text += results[i]
        text += "\n"
        text += urls[i]
        text += "\n"
        text += "</p>"
        

    return text


def NewsFromBBC():
    # BBC news api
    main_url = " https://newsapi.org/v1/articles?source=bbc-news&sortBy=top&apiKey=c7aa00f89fc44825823f79ba0a3899ad"

    # fetching data in json format
    open_bbc_page = requests.get(main_url).json()

    # getting all articles in a string article
    article = open_bbc_page["articles"]

    # empty list which will
    # contain all trending news
    results = []
    urls = []
    for ar in article:
        results.append(ar["title"])
        urls.append(ar["url"])

    for i in range(len(results)):
        # printing all trending news
        print(i + 1, results[i])
        print(urls[i])


#function to get top headlines in the US
def allNews():
    # top headlines in the US api
    url = ('http://newsapi.org/v2/top-headlines?'
           'country=us&'
           'apiKey=c7aa00f89fc44825823f79ba0a3899ad')
    response = requests.get(url)
    article = response["articles"]
    
    results = []
    urls = []

    for ar in article:
        results.append(ar["title"])
        urls.append(ar["url"])

    for i in range(len(results)):
        # printing all trending news
        print(i + 1, results[i])
        print(urls[i])