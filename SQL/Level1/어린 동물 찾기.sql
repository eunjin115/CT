-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME
from ANIMAL_INS 
where NOT INTAKE_CONDITION = 'Aged'
order by ANIMAL_ID asc