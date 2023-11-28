#!/bin/bash!!!!!!!!!!!!!!
# Функция для генерации случайной буквы латинского алфавита
generate_random_letter() {
# Получаем случайное число от 0 до 25
random_number=$((RANDOM % 26))

# Преобразуем число в букву, используя ASCII коды (97 - код буквы 'a')
random_letter=$(printf "\\$(printf '%03o' "$((97 + random_number))")")

echo -n "$random_letter"
}

# Задаем длину случайной последовательности (например, 10 букв)
sequence_length=10

# Генерируем случайную последовательность букв
random_sequence=""
for ((i=0; i<sequence_length; i++)); do
random_sequence="${random_sequence}$(generate_random_letter)"
done

echo "Случайная последовательность: $random_sequence"
