import subprocess

col_1 = ""
col_2 = ""
cnt = 0

with open('data_table.csv', 'r') as csvFile:
    for line in csvFile:
        cols = line.split(',')
        col_1 += cols[0] + ', '
        col_2 += cols[1] + ', '

direct_output = subprocess.run(['./part3_calc.out', col_1, col_2], stdout=subprocess.PIPE)
calc_stdout = str(direct_output.stdout)
temp = calc_stdout.split("'")
final = str(temp[1]) #just to make sure

print(final)
