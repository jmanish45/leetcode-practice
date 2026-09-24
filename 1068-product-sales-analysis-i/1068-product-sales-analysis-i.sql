# Write your MySQL query statement below
SELECT p.product_name as product_name ,
s.year as year, s.price as price 
FROM SALES s
LEFT JOIN PRODUCT p
on p.product_id = s.product_id
