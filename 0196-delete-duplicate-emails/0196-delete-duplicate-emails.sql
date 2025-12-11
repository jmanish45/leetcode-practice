# Write your MySQL query statement below
-- DELETE P1
-- FROM Person P1 , Person P2 
-- WHERE P1.email = P2.email
-- AND P1.id > P2.id

DELETE P1 FROM PERSON AS P1 JOIN PERSON AS P2
ON P1.email = P2.email
AND P1.id > P2.id 
