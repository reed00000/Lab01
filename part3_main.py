import csv
import subprocess

col_1 = ""
col_2 = ""
cnt = 0

with open('data_table.csv', newline='') as csvfile:
    dataReader = csv.reader(csvfile)
    for row in dataReader:
        if cnt>0 and cnt<102:
            col_1 += (row[0] + ' ')
            col_2 += (row[1] + ' ')
        cnt += 1

direct_output = subprocess.run(['./part3_calc.out', col_1, col_2], stdout=subprocess.PIPE)

output = direct_output.stdout
print(output)
