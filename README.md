# Algorithms and Programming -5130203/40001  

* Хранилище материалов:  
Репозиторий будет обновляться каждую неделю-среду со всеми инструкциями и файлами, необходимыми для выполнения домашних заданий.  
* Cсылка на репозиторий:  
https://drive.google.com/drive/folders/1txIMMWdt0VNTTujqblcVoLeQ-rT1cqVC  

Инструкции по выполнению домашнего задания:  
  - Срок выполнения заданий составляет 2 недели (проверяйте даты каждого задания)  
  - Задания выполняются в группах по 2 студенты (у них должна быть одна и та же файлов в их репозитории)  
  - Все задачи публикуются в отдельных репозиториях GitHub (исходный код в формате файла .cpp + отчет в формате файла .pdf)  

### Урок 03 – Указатели и ссылки   
----------------------------------
  
  **Гланые Подтемы**:
  - Указатели на переменные  
  - Одинарные и двойные указатели  
  - Указатели на векторы  
  - Указатели на векторы    
    
  **Что такое указателей?**  
  это символические представления адресов.  

  **код синтаксис**  
```
  тип данных *var_name;
  int *ptr; // ptr может указывать на адрес, содержащий данные типа int
```
    
  ![image](https://github.com/user-attachments/assets/c593611e-8662-4bb9-9895-848177ae0f84)  

  Какие функциональности выполняют указатели?  
    
  - позволяют программам имитировать вызов по ссылке;
  - создавать и манипулировать динамическими структурами данных;
  - делают итерация по элементам в массивах или других структурах данных

  указатели на переменные  
    
  ![image](https://github.com/user-attachments/assets/364ca0d1-8d2e-4bb0-a86b-57c6f9a82055)  

  указатели на векторы  
    
  ![image](https://github.com/user-attachments/assets/fd3713c6-a850-4620-bf55-e528a64f49fa)  

  указатели на массивы  
```  
  int nums[2][3] = {
                     { 16, 18, 20 },
                     { 25, 26, 27 }
                   };  
```
  
  ![image](https://github.com/user-attachments/assets/105ec7ef-fe9c-4078-afa7-8adf6b026ddd)  
  
**Совет недели: Как работают компьютеры?**  
  
  КОМПЬЮТЕР — ЭТО СЛОЖНАЯ СИСТЕМА, состоящая из множества различных компонентов. Мозг компьютера — это ЦП (центральный процессор). ЦП — это один чип, задачей которого является выполнение программ.  

  ![image](https://github.com/user-attachments/assets/2ccc610c-0e6d-47e6-b19b-6d13b2812d73)  
  
  - Когда **ЦП** (CPU на английском) выполняет программу, эта программа сохраняется в основной памяти компьютера (также называемой ОЗУ или оперативной памятью).
  - **Основная память** состоит из последовательности ячеек. Эти ячейки пронумерованы, а порядковый номер ячейки называется ее **адресом**.
  - Когда ЦП необходимо получить доступ к инструкции программы или данным в определенной ячейке, он отправляет адрес этой информации в качестве сигнала в память;
  - память отвечает, отправляя обратно значение, содержащееся в указанной ячейке.
  - ЦП также может хранить информацию в памяти, указывая информацию, которую необходимо сохранить, и адрес ячейки, в которой она должна быть сохранена.  
  - Оперативная память (RAM memory на английском) хранит программы и данные на машинном языке. Они кодируются как двоичные числа.
  - ЦП извлекает инструкции машинного языка из памяти одну за другой и выполняет их. Каждая инструкция заставляет ЦП выполнять какую-то очень маленькую задачу. Например: сложение двух чисел или перемещение данных в память или из памяти.  
  
### Урок 02 – Условные и повторяющиеся инструции  
---------------------------------------------------
  
  **Гланые Подтемы**:  
  - повторяющаяся инструкция while;  
  - повторяющаяся инструкция do-while;  
  - повторяющаяся инструкция for;  
  - Использование debugger;
  - Типы данных Char и код ASCII.  

  **Домашнее задание (от 25.09 до 09.10)**:  
    1) Разработать список 02 из 3 упражнений из **файла docs/list02_dz.pdf**  
      (разработать исходный код + подготовить отчет с блок-схема + скриншот с тестами в отчете + публикация на GitHub)  
      - разработать исходный код + публикация на GitHub  
      - В каждом упражнении (1, 2, 3) выберите только один вариант и затем создайте блок-схему  
      - подготовьте отчет с 3-мя ранее упомянутыми блок-схемами и скриншотом 1 теста для каждого варианта каждого упражнения  
    2) Проведите эксперименты с debugger и/или терминалом, используя разные значения переменных и проверьте обновленные значения переменных (задачи 9.1, 9.2, 9.3) из файла **docs/lab1.cpp**.  
 Подготовить отчет со скриншотами проведенных экспериментов (по 2 теста на каждую задачу). **Отчет должен быть опубликован на GitHub (pdf)**.   
   
  **Совет недели: Блок-схема и синтаксис программирования**  

  - оператор switch-case
    
  **блок схема**  
    
  ![image](https://github.com/user-attachments/assets/38fcef05-9313-4fd7-90a9-e006f114e1d7)  

  **код синтаксис**  
  
```
    switch (выражение) { 
      case value_1 : 
          // операторы_1;
           break; 
      case value_2 : 
          // операторы_2;
           break; 
      ..... 
      ..... 
      default: 
          // операторы_по_умолчанию;
           break; 
    }
```
  
  - оператор while  
  
  **блок схема**  
    
  ![image](https://github.com/user-attachments/assets/733d0422-481f-447c-9a7f-aceffe0c5ab3)  

  **код синтаксис**  
  
```
  выражение инициализации;
  while(test_expression) 
  { 
     // операторы update_expression; 
   }
```
    
  - оператор do-while  
  
  **блок схема**  
    
  ![image](https://github.com/user-attachments/assets/726db14a-2e85-440a-9f51-5b87cef4c986)  
    
  **код синтаксис**  
      
```
  выражение инициализации;
  do 
  { 
     // операторы update_expression; 
  } while(test_expression);  
```
  
  - оператор for   
    
  **блок схема**  
    
  ![image](https://github.com/user-attachments/assets/90a304b6-3ca1-4883-a4cb-474e957ce1a7)   
    
  **код синтаксис**  

```      
  for(initialization expr; conditional expr; update expr)
  {     
       // тело цикла 
       // операторы, которые мы хотим выполнить 
  }
```
  
  - Код ASCII  
   
  Таблица ASCII (**A**merican **S**tandard **C**ode for **I**nformation **I**nterchange)  
    
  ![ascii_code](https://github.com/user-attachments/assets/a596bf61-bc1e-4375-a43f-a9666c8cb9f5)  
    
    
### Неделя 01 – Последовательно и управляющие инструции  
--------------------------------------------------------  
  
  **Гланые Подтемы**:  
  - Фундаментальные основы программирования на C++;
  - Константы, переменные и типы данных в C++;
  - Последовательные инструкции;
  - Условные инструкции.  
  
  **Домашнее задание (от 11.09 до 18.09)**:  
    1) Разработка программы 05 (слайд 06 — **файл slides/week01.ppt**): Исходный код + публикация на GitHub.  
    2) Разработать список 01 из 4 упражнений из **файла docs/list01_dz.pdf**  
      (разработать исходный код + подготовить отчет с псевдокод логики программирования + скриншот 2 тестов в отчете + публикация на GitHub)  
    3) Провести эксперименты с отладчиком, используя различные значения переменных и проверить обновление значений (задачи 1, 2.а, 2.б) файла **docs/lab1.cpp**.  
       Следовать инструкциям, дополнить исходный код + опубликовать на GitHub + подготовить отчет со скриншотом проведенных экспериментов (по 2 теста на каждое задачи)
  
  **Совет недели: Итеративный процесс оценки алгоритмов**  
  
  ![image](https://github.com/user-attachments/assets/e17f686e-0182-491e-84b6-c1bd51f1a75d)  
    
