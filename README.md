# Nasa_apps_challenge_cotonou_eeig
Code for EILG

#Contenu du dossier

# Description
Au Bénin, nous observons une mauvaise régularisation des flux de circulations, un mauvais fonctionnement des feux tricolores en place ce qui obligent un policier à devoir se positionner pour faire manuellement la régularisation. Hier l’organisation de la circulation des véhicules dans un carrefour se faisait par l’homme, depuis la naissance des systèmes d'automatisation et de détection les carrefours sont contrôlés par des automates plus ou moins intelligents. 
D'ou la naissance de l'idée de gestion automatisée et plus efficiente de l'existant.
Ce projet a pour objectif la conception d'un système de commande en temps réel en utilisant ARDUINO et LABVIEW. Ceci sera illustré par l’automatisation des feux d'un carrefour en gérant les séquences des feux et les détections de véhicules et de piétons. Il s'agit aussi d'une interface de supervision à distance pour le contrôle de l'ensemble du système. Ainsi, le système offre une possibilité de prise en main manuelle par un humain.
Actuellement, nous avions réalisé une maquette pour un carrefour avec arduino et labView. La fonctionnalité de base au niveau du carrefour marche bien. Cette fonctionnalité est répartie en trois modes : Le mode fonctionnement normal, mode forcé et le mode fonctionnement personnalisé. 
Lorsque le mode fonctionnement normal est choisi, on peut paramétrer la durée d’allumage du Vert, du Jaune et du Rouge de chaque voie. Ces temps sont identiques pour toutes les voies.
Lorsque le mode fonctionnement personnalisé est choisi, on peut paramétrer la durée d’allumage des lampes de chaque voie. Ces durées peuvent être différentes pour toutes les lampes du feu tricolore.
Lorsque le mode forcé est choisie, on peut forcer l’allumage de la lampe verte ou de la lampe rouge sur n’importe quelle voie.
Ces différentes configurations sont effectuées via une interface de supervision crée avec labVIEW.
L’état dynamique des feux tricolores est présenté aussi bien sur la maquette que dans l’interface de supervision.
La communication entre Arduino et LabVIEW  est effectuer pour USB.

