select year(a_data) as Ano, cast(sum(preco) as DECIMAL(9,2)) as 'Consumos [€]' from abastecimento group by year(a_data)