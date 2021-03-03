# HackerRank SQL



#### Revising the Select Query I

https://www.hackerrank.com/challenges/revising-the-select-query/problem

```
select *  from city where population > 100000 and city.countrycode = 'USA'
```



#### Select All

https://www.hackerrank.com/challenges/select-all-sql/problem

```
select * from city
```



#### Select By ID

https://www.hackerrank.com/challenges/select-by-id/problem

```
select * from city where city.id = 1661
```



#### Japanese Cities' Attributes

https://www.hackerrank.com/challenges/japanese-cities-attributes/problem

```
select * from city where city.countrycode = 'JPN'
```



#### Japanese Cities' Names

https://www.hackerrank.com/challenges/japanese-cities-name/problem

```
select city.name from city where city.countrycode = 'JPN'
```



#### Weather Observation Station 1

https://www.hackerrank.com/challenges/weather-observation-station-1/problem

```
select s.city, s.state  from station as s
```



#### Weather Observation Station 3

https://www.hackerrank.com/challenges/weather-observation-station-3/problem

```
select distinct s.city from station as s where s.id % 2 = 0
```



#### Weather Observation Station 4

https://www.hackerrank.com/challenges/weather-observation-station-4/problem

```
select (count(s.city) - count(distinct s.city)) from station as s
```



#### Weather Observation Station 5

https://www.hackerrank.com/challenges/weather-observation-station-5/problem

```
select s.city, char_length(s.city) as cl from station as s order by cl, s.city limit 1;
select s.city, char_length(s.city) as cl from station as s order by cl desc, s.city asc limit 1;
```



#### Weather Observation Station 6

https://www.hackerrank.com/challenges/weather-observation-station-6/problem

```
select distinct s.city from station as s where s.city like 'a%' or s.city like 'e%' or s.city like 'i%' or s.city like 'o%' or s.city like 'u%'

select distinct s.city from station as s where s.city REGEXP "^[aeiou].*";
```



#### Weather Observation Station 7

https://www.hackerrank.com/challenges/weather-observation-station-7/problem

```
select distinct s.city from station as s where s.city REGEXP ".*[aeiou]$";
```



#### Weather Observation Station 8

https://www.hackerrank.com/challenges/weather-observation-station-8/problem

```
select distinct s.city from station as s where s.city REGEXP "^[aeiou].*[aeiou]$";
```



#### Weather Observation Station 9

https://www.hackerrank.com/challenges/weather-observation-station-9/problem

```
select distinct s.city from station as s where s.city REGEXP "^[^aioeu].*";
```



#### Weather Observation Station 10

https://www.hackerrank.com/challenges/weather-observation-station-10/problem

```
select distinct s.city from station as s where s.city REGEXP ".*[^aioeu]$";
```



#### Weather Observation Station 11

https://www.hackerrank.com/challenges/weather-observation-station-11/problem

```
select distinct s.city from station as s where s.city REGEXP "(^[^aioeu].*)|(.*[^aioeu]$)";
```



#### Weather Observation Station 12

https://www.hackerrank.com/challenges/weather-observation-station-12/problem

```
select distinct s.city from station as s where s.city REGEXP "(^[^aioeu].*[^aioeu]$)";
```

