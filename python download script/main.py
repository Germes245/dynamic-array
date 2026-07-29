from pathlib import Path
from jinja2 import Environment
import json
from os import mkdir
import sys, os
def template_folder(name_of_containg_templates_folder, name_of_folder_for_generated_code, dicto):
    """
    Рекурсивно обрабатывает все файлы в папке шаблонов:
    - содержимое каждого файла рендерится как шаблон Jinja2;
    - имя каждого файла также обрабатывается как шаблон (с теми же данными);
    - результаты сохраняются в целевую папку с сохранением структуры подкаталогов.

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
            # Относительный путь от корня шаблонов (содержит подпапки)
            rel_path = os.path.relpath(src_path, name_of_containg_templates_folder)

            # Разделяем путь на каталог и имя файла
            rel_dir = os.path.dirname(rel_path)   # может быть пустой строкой
            old_filename = os.path.basename(rel_path)

            # Рендерим имя файла как шаблон
            filename_template = env.from_string(old_filename)
            new_filename = filename_template.render(**dicto)

            # Собираем новый относительный путь (папки не шаблонизируются)
            if rel_dir:
                new_rel_path = os.path.join(rel_dir, new_filename)
            else:
                new_rel_path = new_filename

            # Целевой путь в папке назначения
            dst_path = os.path.join(name_of_folder_for_generated_code, new_rel_path)

            # Создаём родительские каталоги
            dst_dir = os.path.dirname(dst_path)
            if dst_dir:
                os.makedirs(dst_dir, exist_ok=True)

            # Загружаем шаблон по исходному (старому) относительному пути и рендерим содержимое
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

template_folder("../code", "build", dicto)
template_folder("../code", "build", dicto)