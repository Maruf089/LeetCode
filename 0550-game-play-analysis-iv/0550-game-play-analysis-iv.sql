# Write your MySQL query statement below

With T as (
Select player_id , min(event_date) as event_date
From Activity
Group by player_id
)
Select round(count(player_id)/( select count(distinct T.player_id) from T), 2) as fraction
From Activity
Where (player_id, DATE_SUB(event_date, Interval 1 Day)) IN (
    Select player_id , event_date
    From T
)
