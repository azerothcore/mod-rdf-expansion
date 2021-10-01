# mod-rdf-expansion

Allows to join RDF of previous expansions on a higher character level.

Up to character level 58, you can join the "Random Classic Dungeon":

<img alt="RDF at level 58" src="https://user-images.githubusercontent.com/75517/135634608-fd8b52c2-2939-42c9-a848-813d169d19cd.png" width=300>

However, once the character level hits 59, you can no longer join "Random Classic Dungeon" but you can only join "Random Burning Crusade Dungeon":

<img alt="RDF at level 59" src="https://user-images.githubusercontent.com/75517/135634558-64808499-9a45-4d1f-b9fc-a962ab7e63bb.png" width=300>

This is a client limitation. This module allows to hijack the type of RDF according to the configuration.

```
#
#     RDF.Expansion
#        Description: Allow setting which expansion can be used in LFG
#           2 - WOTLK (Default behaviour)
#           1 - TBC (if the player queues WOTLK RDF, join as TBC RDF)
#           0 - Classic  (if the player queues Wotlk or TBC RDF, join as Classic RDF)
#        Default:     2

RDF.Expansion = 2
```


## Requirements

Requires a version of AC with https://github.com/azerothcore/azerothcore-wotlk/pull/8196 or higher


## Installation


1) Simply `git clone` the module under the `modules` directory of your AzerothCore source or copy paste it manually.
2) Re-run cmake and launch a clean build of AzerothCore
3) Copy `mod-rdf-expansion.conf.dist` to `mod-rdf-expansion.conf` and edit as you please


## Credits

* [Shin](https://github.com/FrancescoBorzi)
* [Yehonal](https://github.com/Yehonal)
* AzerothCore: [repository](https://github.com/azerothcore) - [website](http://azerothcore.org/) - [discord chat community](https://discord.gg/PaqQRkd)
