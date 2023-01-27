-- 코드를 입력하세요
SELECT count(*) USERS
from USER_INFO
where age >= 20 and age <=29
and to_char(joined, 'YYYY') = '2021' --convert 함수로 연도만 가져옴 