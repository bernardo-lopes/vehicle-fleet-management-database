select a.marca as Gasolineira, count(*) as 'Nº de abastecimentos' from abastecimento inner join (select nome, gasolineira.marca from posto inner join gasolineira on gasolineira.marca=posto.marca) as a on a.nome=abastecimento.nome group by a.marca order by count(*) desc