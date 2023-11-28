#!/bin/bash
# Проверяем, передано ли имя команды в качестве аргумента
if [ $# -ne 1 ]; then
echo "Использование: $0 <имя_команды>"
exit 1
fi

command_name="$1"
man_directory="/home/atg/Documents"
man_file="$man_directory/$command_name.1"

# Проверяем существование файла справки для указанной команды
if [ -e "$man_file" ]; then
# Открываем справку с использованием less
less "$man_file"
else
echo "Справка для '$command_name' не naidena."
fi
