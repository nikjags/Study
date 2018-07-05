PROGRAM qwerty
  !Программа проверки функций xor,disjunct,conjunct,negation
  LOGICAL a,b !Переменные для хранения значений
  LOGICAL xor,disjunct,conjunct,negation !объявление типа возвращаемого функциями значения

  !Проверка отрицания
  a=.TRUE.
  PRINT *,'a=',a
  PRINT *,'negation(a) = ',negation(a),', correct value =', .FALSE.
  a=.FALSE.
  PRINT *,'a=',a
  PRINT *,'negation(a) = ',negation(a),', correct value =', .TRUE.

  
  WRITE(*,*)

  !Проверка функций при a = .FALSE. b= .FALSE.
  a=.FALSE.
  b=.FALSE.
  PRINT *,'a =',a,'; b =',b
  PRINT *,'xor(a,b) =',xor(a,b),',      correct value =', .FALSE.
  PRINT *,'disjunct(a,b) =',disjunct(a,b),', correct value =', .FALSE.
  PRINT *,'conjunct(a,b) =',conjunct(a,b),', correct value =', .FALSE.

  WRITE(*,*)

  !Проверка функций при a = .FALSE. b= .TRUE.
  a=.FALSE.
  b=.TRUE.
  PRINT *,'a =',a,'; b =',b
  PRINT *,'xor(a,b) =',xor(a,b),',      correct value =', .TRUE.
  PRINT *,'disjunct(a,b) =',disjunct(a,b),', correct value =', .TRUE.
  PRINT *,'conjunct(a,b) =',conjunct(a,b),', correct value =', .FALSE.

  WRITE(*,*)

  !Проверка функций при a = .TRUE. b= .FALSE.
  a=.TRUE.
  b=.FALSE.
  PRINT *,'a =',a,'; b =',b
  PRINT *,'xor(a,b) =',xor(a,b),',      correct value =', .TRUE.
  PRINT *,'disjunct(a,b) =',disjunct(a,b),', correct value =', .TRUE.
  PRINT *,'conjunct(a,b) =',conjunct(a,b),', correct value =', .FALSE.

  WRITE(*,*)

  !Проверка функций при a = .TRUE. b= .TRUE.
  a=.TRUE.
  b=.TRUE.
  PRINT *,'a =',a,'; b =',b
  PRINT *,'xor(a,b) =',xor(a,b),',      correct value =', .FALSE.
  PRINT *,'disjunct(a,b) =',disjunct(a,b),', correct value =', .TRUE.
  PRINT *,'conjunct(a,b) =',conjunct(a,b),', correct value =', .TRUE.

  WRITE(*,*)

    
END PROGRAM qwerty



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
   

