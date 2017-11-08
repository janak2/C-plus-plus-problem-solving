/**
 *Q. Write a SQL query to get the second highest salary from the Employee table.
 *
 */
 
# Write your MySQL query statement below
SELECT MAX(Salary) AS "SecondHighestSalary" FROM Employee
WHERE Salary != (SELECT MAX(Salary) FROM Employee)

# Write your MySQL query statement below
SELECT max(Salary) as SecondHighestSalary FROM Employee WHERE Salary < (SELECT max(Salary) FROM Employee)

# Write your MySQL query statement below
select (
  select distinct Salary from Employee order by Salary Desc limit 1 offset 1
)as SecondHighestSalary
