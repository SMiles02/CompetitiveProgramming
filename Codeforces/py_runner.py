import os
from pathlib import Path
import shutil


directory = r'C:\Users\ayush\Documents\CompetitiveProgramming\Codeforces'
ans = 0
for filename in os.listdir(directory):
    if filename.startswith("CF") and not filename.endswith(".cpp"):
        print(os.path.join(directory, filename))
        temp = filename
        while (len(temp) < 6):
            temp = temp[:2] + '0' + temp[2:]
        print(temp)
        newpath = directory + '\\' + temp
        print(newpath)
        if not os.path.exists(newpath):
            os.makedirs(newpath)
        #Path(directory + '\\' + filename).rename(newpath)
        shutil.move(directory + '\\' + filename, newpath)