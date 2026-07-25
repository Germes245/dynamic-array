from pathlib import Path
from jinja2 import Environment
import json
from os import mkdir
import sys, os

def template_folder(name_of_containg_templates_folder, name_of_folder_for_generated_code, dicto):
    p = Path('text')
    for i in (str(x) for x in p.rglob('*') if x.is_file()):
        with open(i, "r") as file:
            try:text = Environment().from_string(file.read()).render(dicto)
            except:pass
            i = i.split('/')
            i[0] = name_of_folder_for_generated_code
            dir = [a for a in i]
            i = '/'.join(i)
            new_file = Environment().from_string(dir[-1]).render(dicto)
            #print(new_file)
            del dir[-1]
            try: mkdir('/'.join(dir))
            except: pass
            dir.append(new_file)
            dir = '/'.join(dir)
            print(dir)
            with open(dir, "w") as file2:
                file2.write(text)

print("введите желаемый тип, а для конца ввода введите EOF (Ctrl + D):")
buffer = ''

# чтение потока stdin
for i in sys.stdin:
    buffer += i

print("\n")
print(buffer)

print(os.listdir('../').index("type.h"))