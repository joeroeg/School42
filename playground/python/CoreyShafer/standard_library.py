import math
import datetime
import calendar
import os

print(dir(math)) # list of all the functions in the math module

print(math.pi)
print(math.e)

print(math.inf)
print(math.nan)

print(math.log(math.e))
print(math.log(100, 10))

print(math.sin(math.pi/2))
print(math.cos(math.pi/2))

print(math.degrees(math.pi/2))
print(math.radians(90))

print(math.sqrt(100))
print(math.pow(2, 3))

print(math.floor(2.9))
print(math.ceil(2.9))

print(dir(datetime))
print(datetime.date.today())
print(datetime.datetime.now())
print(datetime.datetime.now().time())

print(calendar.isleap(2020))
print(calendar.isleap(2021))
print(calendar.month(2020, 1))
print(calendar.monthcalendar(2020, 1))
print(calendar.calendar(2020))
print(calendar.weekday(2020, 1, 1))
print(calendar.monthrange(2020, 1))
print(calendar.weekheader(3))

print(os.getcwd()) # current working directory
print(os.__file__) # path to the os module file in the standard library
