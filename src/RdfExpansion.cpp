/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "Config.h"

// Add player scripts
class RdfExpansion : public PlayerScript
{
public:
    RdfExpansion() : PlayerScript("RdfExpansion") { }

    void OnQueueRandomDungeon(Player* /* player */, uint32 & rDungeonId) override
    {
        // values from LFGDungeons.dbc
        constexpr const uint32 RDF_CLASSIC = 258;
        constexpr const uint32 RDF_THE_BURNING_CRUSADE = 259;
        constexpr const uint32 RDF_THE_BURNING_CRUSADE_HEROIC = 260;
        constexpr const uint32 RDF_WRATH_OF_THE_LICH_KING = 261;
        constexpr const uint32 RDF_WRATH_OF_THE_LICH_KING_HEROIC = 262;

        switch (sConfigMgr->GetOption<uint32>("RDF.Expansion", 2))
        {
            case EXPANSION_CLASSIC:
                // always force classic RDF
                rDungeonId = RDF_CLASSIC;
                break;
            case EXPANSION_THE_BURNING_CRUSADE:
                // select at most RDF_THE_BURNING_CRUSADE_*
                if (rDungeonId == RDF_WRATH_OF_THE_LICH_KING)
                {
                    rDungeonId = RDF_THE_BURNING_CRUSADE;
                }
                else if (rDungeonId == RDF_WRATH_OF_THE_LICH_KING_HEROIC)
                {
                    rDungeonId = RDF_THE_BURNING_CRUSADE_HEROIC;
                }
            case EXPANSION_WRATH_OF_THE_LICH_KING:
            default:
                // keep the original value
                break;
        }
    }
};

// Add all scripts in one
void AddRdfExpansionScripts()
{
    new RdfExpansion();
}
