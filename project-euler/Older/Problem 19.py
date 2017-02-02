#Problem 19
#You are given the following information, but you may prefer to do some research for yourself.
#1 Jan 1900 was a Monday.
#Thirty days has September,
#April, June and November.
#All the rest have thirty-one,
#Saving February alone,
#Which has twenty-eight, rain or shine.
#And on leap years, twenty-nine.
#A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
#How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

sundaythefirst = []
date = "1-1-1900"
day = 1
month = 1
year = 1900
count = 1

while date!="31-12-2000":
    count += 1

    day += 1
    if month==9 or month==4 or month==6 or month==11:
        if day>30:
            day = 1
            month += 1
    elif month==2:
        if year%4==0: #leap year
            if day>29:
                day = 1
                month += 1
        else: #not leap year
            if day>28:
                day = 1
                month += 1
    else:
        if day>31:
            day = 1
            month += 1

    #check for year
    if month>12:
        month = 1
        year += 1

    #write out the date
    date = "%i-%i-%i" %(day, month, year)

    #name the day
    if count%7==1:
        name = "Monday"
    elif count%7==2:
        name = "Tuesday"
    elif count%7==3:
        name = "Wednesday"
    elif count%7==4:
        name = "Thursday"
    elif count%7==5:
        name = "Friday"
    elif count%7==6:
        name = "Saturday"
    elif count%7==0:
        name = "Sunday"
    
    #check for Sunday the 1st
    if count%7==0 and day==1 and year>1900:
        print date, name
        sundaythefirst.append(date)

print len(sundaythefirst)
