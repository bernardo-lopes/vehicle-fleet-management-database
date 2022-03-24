select posto.marca as Gasolineira,
 cast(sum(case when year(a_data)='2019' then preco-(((preco/litros)-gasolineira.desconto)*litros) else 0 end) as DECIMAL(9,2)) 
 as 'Reembolso de 2019 [€]',
 cast(sum(case when year(a_data)='2020' then preco-(((preco/litros)-gasolineira.desconto)*litros) else 0 end) as DECIMAL(9,2))
 as 'Reembolso de 2020 [€]' 
 
 from (abastecimento inner join posto on abastecimento.nome=posto.nome) 
 inner join gasolineira on gasolineira.marca=posto.marca 
 group by posto.marca