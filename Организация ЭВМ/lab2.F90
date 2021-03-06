PROGRAM main
  !��������� �������� ��������������������� ���������.
  INTEGER dex1,dex2 !������������ �����

  write(*,*)

  write(*,*) '�������� ������������� ����� ��� ������������:'  
  dex1=495
  dex2=3215
  call add(dex1,dex2) !����� ������������, �������������� ��������

  dex1=13295
  dex2=3124
  call add(dex1,dex2)

  write(*,*) '�������� ������������� ����� � �������������:'  
  dex1=18032
  dex2=21076
  call add(dex1,dex2)

  dex1=25754
  dex2=19357
  call add(dex1,dex2)

  dex1= 16384
  dex2= 16384
  call add(dex1,dex2)


  write(*,*) '�������� ������������� ����� ��� ������������:'  
  dex1=-5489
  dex2=-23232
  call add(dex1,dex2)

  dex1=-16533
  dex2=-4534
  call add(dex1,dex2)

  write(*,*) '�������� ������������� ����� � �������������:'  
  dex1=-19232
  dex2=-25403
  call add(dex1,dex2)

  dex1=-27630
  dex2=-12344
  call add(dex1,dex2)



  write(*,*)'�������� ����� � ������� �������:'

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


!������������
SUBROUTINE half_adder(x1,x2,S,C)
  LOGICAL x1,x2,S,C
  !x1,x2 - ������������ �������
  !S - ����� ��������
  !� - �������
  LOGICAL xor,conjunct !���������� ����, ������� ������������ ��������� xor,conjunct

  S=xor(x1,x2)
  C=conjunct(x1,x2)
END SUBROUTINE half_adder

!������������� ��������
SUBROUTINE full_one_adder(x1,x2,S,C)
  !x1,x2 - ������������ �������
  !S - ����� ��������
  !� - �������
  LOGICAL x1,x2,S,C
  LOGICAL S1,C1,S2,C2 !�������� ��������� ����� ������ ������� � ������� �������������

  call half_adder(x1,x2,S1,C1)
  call half_adder(C,S1,S,C2)
  C=C1.OR.C2
  
END SUBROUTINE full_one_adder

!�������������������� ��������
SUBROUTINE full_sixteen_adder(N1,N2,S)
  !N1,N2 - ������ LOGICAL ���������, ������� ��������� �������
  LOGICAL N1(16),N2(16),S(16),C
  LOGICAL C_buffer
  INTEGER i
    
  C_buffer=.FALSE. !��������� ����������, � ������� �������� �������. ���������� �������� ���
  DO i=1,16
     call full_one_adder(N1(i),N2(i),S(i),C_buffer) !����������� ����� �������������� ���������
  END DO
END SUBROUTINE full_sixteen_adder

!������������, ����������� ���������� ����� � ������ LOGICAL �� 16 ���������
SUBROUTINE ten_to_2(dec,bin)
  !dec - �����, ������� ��������� ���������
  !bin - ������ LOGICAL, � ������� ������������ �������
  INTEGER dec,dec_buf                   !��������������� ����������
  LOGICAL bin(16),plus_one(16),bin2(16)          !� �������
  INTEGER i

  dec_buf=abs(dec)       !��������������� ���������� ��� ��������� ��������� ������� bin
  
  DO i=1,16              !
     bin(i)=.FALSE.      !
     plus_one(i)=.FALSE. !������, � ������� � �������� ���� �������� ����� 1. 
  END DO                 !���� ������ ��������� ��� ��������
  plus_one(1)=.TRUE.     !��� �������� � �������������� ���.

  i=1
  DO WHILE (dec_buf.GT.0)          !���� dec_buf ������ ����
     IF(mod(dec_buf,2).EQ.1) THEN  !���������� � bin(i) .TRUE., ���� ������� ������� dec_buf �� 2
        bin(i)=.TRUE.              !����� �������
     ELSE                          !����� ���������� .FALSE.
        bin(i)=.FALSE.
     END IF
     dec_buf=dec_buf/2             !dec_buf ���������� ����� ����� ����� �� ������� dec_buf �� 2.
     i=i+1
  END DO
  
  IF(dec.LT.0) THEN                 !���� ����� ���� ������ ����, 
     DO i=1,16                      !��������� ������ bin � �������� ���
        IF(bin(i).EQV..FALSE.) THEN 
           bin(i)=.TRUE.           
        ELSE                        
           bin(i)=.FALSE.          
        END IF                     
     END DO
     CALL full_sixteen_adder(bin,plus_one,bin) !��������� � ��������� �������� � bin ������� (������ plus_one)
  END IF  
END SUBROUTINE

!������������, ����������� ������ LOGICAL �� 16 ��������� � ���������� �����
SUBROUTINE two_to_10(bin,dec)
  !bin - ������ LOGICAL, ������� ��������� ���������
  !dec - ����� �����, � ������� ��������� ��������� ��������
  LOGICAL bin(16),plus_one(16),bin2(16),sign
  INTEGER dec
  INTEGER i

  DO i=1,16
     plus_one(i)=.FALSE. !��������� ������, � ������� ����� ��������� �������� 1
  END DO
  plus_one(1)=.TRUE.
  
  dec=0
  sign=.FALSE.
  if(bin(16).EQV..TRUE.) THEN !���� ����� � �������������� ����,��������� ��� � ������� ���
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
     if(bin(i).EQV..TRUE.) THEN    !������� dec ����� ������� � bin � ������� ������.
        dec=dec+2**(i-1)
     END IF
  END DO
  
  if(sign.EQV..TRUE.) THEN
     dec=-dec
     END IF
     
END SUBROUTINE two_to_10

!������������, �������������� ������������ � ��������� ��������� �������� �� �����
SUBROUTINE add(a,b)
  !a,b - �����, ������� ��������� �������
  INTEGER a,b,s_dex
  LOGICAL bin1(16),bin2(16),sum(16)
  !bin1 - ������, �������� �������� ������������� ������� ������������� �����
  !bin2 - ������, �������� �������� ������������� ������� ������������� �����
  !sum  - ������, �������� �������� ������������� ����� �����
  LOGICAL conjunct,negation

  write(*,*)
  
  CALL ten_to_2(a,bin1) !������� ����� � ������� LOGICAL
  CALL ten_to_2(b,bin2)

  WRITE(*,'(A2,I0)')'a=',a          !����� ������ ����� � ���������� ��
  WRITE(*,'(A2,I0)')'b=',b
  WRITE(*,'(A13,$)')'binary a    ='  
  DO i=16,1,-1
     write(*,'(L,$)') bin1(i)
  END DO                            !����� ������ ����� � �������� ��
  write(*,*)
  WRITE(*,'(A13,$)')'binary b    ='
  DO i=16,1,-1
     write(*,'(L,$)') bin2(i)
  END DO

  write(*,*)
  
  CALL full_sixteen_adder(bin1,bin2,sum) !���������� ������� ����� ��������

  IF( ((conjunct(bin1(16),bin2(16))).EQV..TRUE.).AND.(sum(16).EQV..FALSE.)) THEN
                                                    !���� � �������� ����� ������������ �������� ����� .TRUE.,
     WRITE(*,'(A23)')'��������� ������������:'      !���� � �������� ����� ������������ �������� ����� .TRUE.,
             WRITE(*,'(A13,$)')'binary sum  ='      !� � ������� ����� .FALSE., �� ��������� ������������
        DO i=16,1,-1                                !(��� �������� ������������� �����)
           WRITE(*,'(L,$)') sum(i)                  !������� ������ ����� � �������� � ���������� ����
        END DO                                     
        WRITE(*,*)
        CALL two_to_10(sum,s_dex)
        WRITE(*,'(A25,I0)')'���������� ����� a � b = ',s_dex
  ELSE
     IF( ( (conjunct(negation(bin1(16)),negation(bin2(16)))).EQV..TRUE.).AND.(sum(16).EQV..TRUE.)) THEN
        WRITE(*,'(A23)')'��������� ������������:'         !���� � �������� ����� ������������ �������� ����� .FALSE.,
        WRITE(*,'(A13,$)')'binary sum  ='                 !� � ������� ����� .TRUE.,
        DO i=16,1,-1                                      !�� ��������� ������������
           WRITE(*,'(L,$)') sum(i)                        !(��� �������� ������������� �����)
        END DO                                            !������� ������ ����� � �������� � ���������� ����
        WRITE(*,*)
        CALL two_to_10(sum,s_dex)
        WRITE(*,'(A25,I0)')'���������� ����� a � b = ',s_dex
     ELSE                                                 !���� ������������ �� ���������, ���������
                                                          !����� � ���������� ��� � ������� �� �����
        WRITE(*,'(A13,$)')'binary sum  ='
        DO i=16,1,-1
           write(*,'(L,$)') sum(i)
        END DO
        CALL two_to_10(sum,s_dex) 
        write(*,*)
        WRITE(*,'(A25,I0)')'���������� ����� a � b = ',s_dex
     END IF
  END IF 
  write(*,*)
  write(*,*)
END SUBROUTINE



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
