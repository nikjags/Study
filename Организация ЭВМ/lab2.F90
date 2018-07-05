PROGRAM main
  !Программа проверки шестнадцатиразрядного сумматора.
  INTEGER dex1,dex2 !Складываемые числа

  write(*,*)

  write(*,*) 'Сложение положительных чисел без переполнения:'  
  dex1=495
  dex2=3215
  call add(dex1,dex2) !Вызов подпрограммы, обрабатывающей сложение

  dex1=13295
  dex2=3124
  call add(dex1,dex2)

  write(*,*) 'Сложение положительных чисел с переполнением:'  
  dex1=18032
  dex2=21076
  call add(dex1,dex2)

  dex1=25754
  dex2=19357
  call add(dex1,dex2)

  dex1= 16384
  dex2= 16384
  call add(dex1,dex2)


  write(*,*) 'Сложение отрицательных чисел без переполнения:'  
  dex1=-5489
  dex2=-23232
  call add(dex1,dex2)

  dex1=-16533
  dex2=-4534
  call add(dex1,dex2)

  write(*,*) 'Сложение отрицательных чисел с переполнением:'  
  dex1=-19232
  dex2=-25403
  call add(dex1,dex2)

  dex1=-27630
  dex2=-12344
  call add(dex1,dex2)



  write(*,*)'Сложение чисел с разными знаками:'

  dex1= 20302
  dex2=-15851
  call add(dex1,dex2)

  dex1= 5302
  dex2=-25851
  call add(dex1,dex2)

  dex1= 14337
  dex2=-14337
  call add(dex1,dex2)

  dex1= 32000
  dex2=-32233
  call add(dex1,dex2)
    
END PROGRAM main


!Полусумматор
SUBROUTINE half_adder(x1,x2,S,C)
  LOGICAL x1,x2,S,C
  !x1,x2 - складываемые разряды
  !S - сумма разрядов
  !С - перенос
  LOGICAL xor,conjunct !объявление типа, который возвращается функциями xor,conjunct

  S=xor(x1,x2)
  C=conjunct(x1,x2)
END SUBROUTINE half_adder

!Одноразрядный сумматор
SUBROUTINE full_one_adder(x1,x2,S,C)
  !x1,x2 - складываемые разряды
  !S - сумма разрядов
  !С - перенос
  LOGICAL x1,x2,S,C
  LOGICAL S1,C1,S2,C2 !Выходные параметры после работы первого и второго полусумматора

  call half_adder(x1,x2,S1,C1)
  call half_adder(C,S1,S,C2)
  C=C1.OR.C2
  
END SUBROUTINE full_one_adder

!Шестнадцатиразрядный сумматор
SUBROUTINE full_sixteen_adder(N1,N2,S)
  !N1,N2 - массив LOGICAL элементов, которые требуется сложить
  LOGICAL N1(16),N2(16),S(16),C
  LOGICAL C_buffer
  INTEGER i
    
  C_buffer=.FALSE. !Обнуление переменной, в которой хранится перенос. Изначально переноса нет
  DO i=1,16
     call full_one_adder(N1(i),N2(i),S(i),C_buffer) !Циклический вызов одноразрядного сумматора
  END DO
END SUBROUTINE full_sixteen_adder

!Подпрограмма, переводящая десятичное число в массив LOGICAL из 16 элементов
SUBROUTINE ten_to_2(dec,bin)
  !dec - число, которое требуется перевести
  !bin - массив LOGICAL, в который производится перевод
  INTEGER dec,dec_buf                   !Вспомогательные переменные
  LOGICAL bin(16),plus_one(16),bin2(16)          !и массивы
  INTEGER i

  dec_buf=abs(dec)       !Вспомогательная переменная для получения элементов массива bin
  
  DO i=1,16              !
     bin(i)=.FALSE.      !
     plus_one(i)=.FALSE. !Массив, в котором в двоичном виде хранится число 1. 
  END DO                 !этот массив необходим для сложения
  plus_one(1)=.TRUE.     !при переводе в дополнительный код.

  i=1
  DO WHILE (dec_buf.GT.0)          !Пока dec_buf больше нуля
     IF(mod(dec_buf,2).EQ.1) THEN  !записываем в bin(i) .TRUE., если остаток деления dec_buf на 2
        bin(i)=.TRUE.              !равен единице
     ELSE                          !иначе записываем .FALSE.
        bin(i)=.FALSE.
     END IF
     dec_buf=dec_buf/2             !dec_buf становится равен целой части от деления dec_buf на 2.
     i=i+1
  END DO
  
  IF(dec.LT.0) THEN                 !Если число было меньше нуля, 
     DO i=1,16                      !переводим массив bin в обратный код
        IF(bin(i).EQV..FALSE.) THEN 
           bin(i)=.TRUE.           
        ELSE                        
           bin(i)=.FALSE.          
        END IF                     
     END DO
     CALL full_sixteen_adder(bin,plus_one,bin) !Добавляем к двоичному значению в bin единицу (массив plus_one)
  END IF  
END SUBROUTINE

!Подпрограмма, переводящая массив LOGICAL из 16 элементов в десятичное число
SUBROUTINE two_to_10(bin,dec)
  !bin - массив LOGICAL, который требуется перевести
  !dec - целое число, в которое запишется результат перевода
  LOGICAL bin(16),plus_one(16),bin2(16),sign
  INTEGER dec
  INTEGER i

  DO i=1,16
     plus_one(i)=.FALSE. !Заполняем массив, в котором будет храниться значение 1
  END DO
  plus_one(1)=.TRUE.
  
  dec=0
  sign=.FALSE.
  if(bin(16).EQV..TRUE.) THEN !Если число в дополнительном коде,переводим его в обычный код
     sign=.TRUE.
     DO i=1,16
        IF(bin(i).EQV..FALSE.) THEN 
           bin(i)=.TRUE.
        ELSE
           bin(i)=.FALSE.
        END IF
     END DO
     CALL full_sixteen_adder(bin,plus_one,bin)
  END IF  

  do i=1,15
     if(bin(i).EQV..TRUE.) THEN    !Считаем dec через разряды в bin и степени двойки.
        dec=dec+2**(i-1)
     END IF
  END DO
  
  if(sign.EQV..TRUE.) THEN
     dec=-dec
     END IF
     
END SUBROUTINE two_to_10

!Подпрограмма, обрабатывающая переполнения и выводящая результат сложения на экран
SUBROUTINE add(a,b)
  !a,b - числа, которые требуется сложить
  INTEGER a,b,s_dex
  LOGICAL bin1(16),bin2(16),sum(16)
  !bin1 - массив, хранящий двоичное представление первого складываемого числа
  !bin2 - массив, хранящий двоичное представление второго складываемого числа
  !sum  - массив, хранящий двоичное представление суммы чисел
  LOGICAL conjunct,negation

  write(*,*)
  
  CALL ten_to_2(a,bin1) !Перевод чисел в массивы LOGICAL
  CALL ten_to_2(b,bin2)

  WRITE(*,'(A2,I0)')'a=',a          !Вывод данных чисел в десятичной СС
  WRITE(*,'(A2,I0)')'b=',b
  WRITE(*,'(A13,$)')'binary a    ='  
  DO i=16,1,-1
     write(*,'(L,$)') bin1(i)
  END DO                            !Вывод данных чисел в двоичной СС
  write(*,*)
  WRITE(*,'(A13,$)')'binary b    ='
  DO i=16,1,-1
     write(*,'(L,$)') bin2(i)
  END DO

  write(*,*)
  
  CALL full_sixteen_adder(bin1,bin2,sum) !Складываем массивы через сумматор

  IF( ((conjunct(bin1(16),bin2(16))).EQV..TRUE.).AND.(sum(16).EQV..FALSE.)) THEN
                                                    !Если в разрядах знака складываемых массивов стоят .TRUE.,
     WRITE(*,'(A23)')'Произошло переполнение:'      !Если в разрядах знака складываемых массивов стоят .TRUE.,
             WRITE(*,'(A13,$)')'binary sum  ='      !а в массиве суммы .FALSE., то произошло переполнение
        DO i=16,1,-1                                !(при сложении отрицательных чисел)
           WRITE(*,'(L,$)') sum(i)                  !Выводим массив суммы в двоичном и десятичном виде
        END DO                                     
        WRITE(*,*)
        CALL two_to_10(sum,s_dex)
        WRITE(*,'(A25,I0)')'Десятичная сумма a и b = ',s_dex
  ELSE
     IF( ( (conjunct(negation(bin1(16)),negation(bin2(16)))).EQV..TRUE.).AND.(sum(16).EQV..TRUE.)) THEN
        WRITE(*,'(A23)')'Произошло переполнение:'         !Если в разрядах знака складываемых массивов стоят .FALSE.,
        WRITE(*,'(A13,$)')'binary sum  ='                 !а в массиве суммы .TRUE.,
        DO i=16,1,-1                                      !то произошло переполнение
           WRITE(*,'(L,$)') sum(i)                        !(при сложении положительных чисел)
        END DO                                            !Выводим массив суммы в двоичном и десятичном виде
        WRITE(*,*)
        CALL two_to_10(sum,s_dex)
        WRITE(*,'(A25,I0)')'Десятичная сумма a и b = ',s_dex
     ELSE                                                 !Если переполнений не произошло, переводим
                                                          !сумму в десятичный вид и выводим на экран
        WRITE(*,'(A13,$)')'binary sum  ='
        DO i=16,1,-1
           write(*,'(L,$)') sum(i)
        END DO
        CALL two_to_10(sum,s_dex) 
        write(*,*)
        WRITE(*,'(A25,I0)')'Десятичная сумма a и b = ',s_dex
     END IF
  END IF 
  write(*,*)
  write(*,*)
END SUBROUTINE



!Операция отрицания
LOGICAL FUNCTION negation(a)
  !Если  a = .FALSE.,   то a = .TRUE.;
  !                  иначе a = .FALSE.
  LOGICAL a
  IF(a.EQV..TRUE.) THEN
     negation=.FALSE.
  ELSE
     negation=.TRUE.
  ENDIF
END FUNCTION negation


!Операция дизъюнкции
LOGICAL FUNCTION disjunct(a,b)
  !Если (a OR b) истина,   то функция возвращает значение .TRUE.;
  !                     иначе функция возвращает значение .FALSE.
  LOGICAL a,b  
  IF(a.OR.b) THEN
     disjunct=.TRUE.
  ELSE
     disjunct=.FALSE.
  ENDIF
END FUNCTION disjunct

!Операция конъюнкции
LOGICAL FUNCTION conjunct(a,b)
  !Если (a AND b) истина,   то функция возвращает значение .TRUE.;
  !                      иначе функция возвращает значение .FALSE.
  LOGICAL a,b
    IF (a.AND.b) THEN
     conjunct=.TRUE.
  ELSE
     conjunct=.FALSE.
  ENDIF  
END FUNCTION conjunct

!Операция XOR(сложения по модулю 2)
LOGICAL FUNCTION xor(a,b)
  !Если a не равно b,    то функция возвращает значение .TRUE.;
  !                   иначе функция возвращает значение .FALSE.
  LOGICAL a,b
  IF (a.NEQV.b) THEN
     xor=.TRUE.
  ELSE
     xor=.FALSE.
  ENDIF  
END FUNCTION xor
