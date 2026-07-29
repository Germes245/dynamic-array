from pathlib import Path
from jinja2 import Environment
import json
from os import mkdir
import sys, os

import os
from jinja2 import Environment, FileSystemLoader

def template_folder(name_of_containg_templates_folder, name_of_folder_for_generated_code, dicto):
    """
    Рекурсивно обрабатывает все файлы в папке шаблонов как шаблоны Jinja2,
    рендерит их с переданным словарём и записывает результаты в целевую папку,
    сохраняя структуру подкаталогов.

    Аргументы:
        name_of_containg_templates_folder (str): путь к папке с исходными шаблонами.
        name_of_folder_for_generated_code (str): путь к папке для сохранения сгенерированных файлов.
        dicto (dict): словарь с данными для подстановки в шаблоны.
    """
    # Создаём окружение Jinja2 с загрузчиком из папки шаблонов
    env = Environment(loader=FileSystemLoader(name_of_containg_templates_folder))

    # Обходим все файлы и подпапки в исходной директории
    for root, dirs, files in os.walk(name_of_containg_templates_folder):
        for file in files:
            # Полный путь к исходному файлу
            src_path = os.path.join(root, file)
            # Относительный путь от корня шаблонов (сохраняет структуру подпапок)
            rel_path = os.path.relpath(src_path, name_of_containg_templates_folder)
            # Путь, куда будет записан результат в целевой папке
            dst_path = os.path.join(name_of_folder_for_generated_code, rel_path)

            # Создаём родительские каталоги для целевого файла, если их нет
            dst_dir = os.path.dirname(dst_path)
            if dst_dir:
                os.makedirs(dst_dir, exist_ok=True)

            # Загружаем шаблон по относительному пути и рендерим с переданными данными
            template = env.get_template(rel_path)
            rendered_content = template.render(**dicto)

            # Записываем результат в целевой файл (в кодировке UTF-8)
            with open(dst_path, 'w', encoding='utf-8') as f:
                f.write(rendered_content)

print("введите желаемый тип, а для конца ввода введите EOF (Ctrl + D):")
buffer = ''

# чтение потока stdin
for i in sys.stdin:
    buffer += i

#print("\n")
#print(buffer)

dicto = {"type": buffer}
buffer = ''
print("\nвведите желаемый префикс, а для конца ввода введите EOF (Ctrl + D):")
for i in sys.stdin:
    buffer += i
dicto["prefix"] = buffer

template_folder("../code/src", "build/src", dicto)
template_folder("../code/include", "build/include", dicto)