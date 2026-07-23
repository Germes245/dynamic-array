from pathlib import Path
from jinja2 import Environment
import json
from os import mkdir

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
with open("config.json", "r") as file: dict_ = json.loads(file.read())
template_folder("text", "copia", dict_)
