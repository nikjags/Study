PROGRAM qwerty
  !��������� �������� ������� xor,disjunct,conjunct,negation
  LOGICAL a,b !���������� ��� �������� ��������
  LOGICAL xor,disjunct,conjunct,negation !���������� ���� ������������� ��������� ��������

  !�������� ���������
  a=.TRUE.
  PRINT *,'a=',a
  PRINT *,'negation(a) = ',negation(a),', correct value =', .FALSE.
  a=.FALSE.
  PRINT *,'a=',a
  PRINT *,'negation(a) = ',negation(a),', correct value =', .TRUE.

  
  WRITE(*,*)

  !�������� ������� ��� a = .FALSE. b= .FALSE.
  a=.FALSE.
  b=.FALSE.
  PRINT *,'a =',a,'; b =',b
  PRINT *,'xor(a,b) =',xor(a,b),',      correct value =', .FALSE.
  PRINT *,'disjunct(a,b) =',disjunct(a,b),', correct value =', .FALSE.
  PRINT *,'conjunct(a,b) =',conjunct(a,b),', correct value =', .FALSE.

  WRITE(*,*)

  !�������� ������� ��� a = .FALSE. b= .TRUE.
  a=.FALSE.
  b=.TRUE.
  PRINT *,'a =',a,'; b =',b
  PRINT *,'xor(a,b) =',xor(a,b),',      correct value =', .TRUE.
  PRINT *,'disjunct(a,b) =',disjunct(a,b),', correct value =', .TRUE.
  PRINT *,'conjunct(a,b) =',conjunct(a,b),', correct value =', .FALSE.

  WRITE(*,*)

  !�������� ������� ��� a = .TRUE. b= .FALSE.
  a=.TRUE.
  b=.FALSE.
  PRINT *,'a =',a,'; b =',b
  PRINT *,'xor(a,b) =',xor(a,b),',      correct value =', .TRUE.
  PRINT *,'disjunct(a,b) =',disjunct(a,b),', correct value =', .TRUE.
  PRINT *,'conjunct(a,b) =',conjunct(a,b),', correct value =', .FALSE.

  WRITE(*,*)

  !�������� ������� ��� a = .TRUE. b= .TRUE.
  a=.TRUE.
  b=.TRUE.
  PRINT *,'a =',a,'; b =',b
  PRINT *,'xor(a,b) =',xor(a,b),',      correct value =', .FALSE.
  PRINT *,'disjunct(a,b) =',disjunct(a,b),', correct value =', .TRUE.
  PRINT *,'conjunct(a,b) =',conjunct(a,b),', correct value =', .TRUE.

  WRITE(*,*)

    
END PROGRAM qwerty



!�������� ���������
LOGICAL FUNCTION negation(a)
  !����  a = .FALSE.,   �� a = .TRUE.;
  !                  ����� a = .FALSE.
  LOGICAL a
  IF(a.EQV..TRUE.) THEN
     negation=.FALSE.
  ELSE
     negation=.TRUE.
  ENDIF
END FUNCTION negation


!�������� ����������
LOGICAL FUNCTION disjunct(a,b)
  !���� (a OR b) ������,   �� ������� ���������� �������� .TRUE.;
  !                     ����� ������� ���������� �������� .FALSE.
  LOGICAL a,b  
  IF(a.OR.b) THEN
     disjunct=.TRUE.
  ELSE
     disjunct=.FALSE.
  ENDIF
END FUNCTION disjunct

!�������� ����������
LOGICAL FUNCTION conjunct(a,b)
  !���� (a AND b) ������,   �� ������� ���������� �������� .TRUE.;
  !                      ����� ������� ���������� �������� .FALSE.
  LOGICAL a,b
    IF (a.AND.b) THEN
     conjunct=.TRUE.
  ELSE
     conjunct=.FALSE.
  ENDIF  
END FUNCTION conjunct

!�������� XOR(�������� �� ������ 2)
LOGICAL FUNCTION xor(a,b)
  !���� a �� ����� b,    �� ������� ���������� �������� .TRUE.;
  !                   ����� ������� ���������� �������� .FALSE.
  LOGICAL a,b
  IF (a.NEQV.b) THEN
     xor=.TRUE.
  ELSE
     xor=.FALSE.
  ENDIF  
END FUNCTION xor
   

