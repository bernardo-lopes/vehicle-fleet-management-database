select 
abastecimento.matricula as 'Matrícula', 
max(quilometragem)-min(quilometragem) as 'Quilómetros',
cast(sum(litros) as DECIMAL(9,1)) as 'Litros',

cast((sum(litros)/(max(quilometragem)-min(quilometragem)))*100 as DECIMAL(9,1)) as 'Consumo médio real [L/100Km]',

cast(viatura.consumo_medio as DECIMAL(9,1)) as 'Consumo médio teórico [L/100Km]',

if(round((round(sum(litros),2)/(max(quilometragem)-min(quilometragem)))*100,2)<viatura.consumo_medio*1.2,"OK","NOT OK") as "Critério 20%" 
from abastecimento 
inner join viatura on viatura.matricula=abastecimento.matricula 
group by abastecimento.matricula
order by if(round((round(sum(litros),2)/(max(quilometragem)-min(quilometragem)))*100,2)<viatura.consumo_medio*1.2,"OK","NOT OK"),
(sum(litros)/(max(quilometragem)-min(quilometragem)))*100-viatura.consumo_medio desc 

