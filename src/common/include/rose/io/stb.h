#pragma once

#include <filesystem>
#include <vector>

namespace Rose {
namespace IO {
class BinaryReader;
}
}

// This comes from data_type.h but we can't import it here
const size_t STB_FILE_COUNT = 14;


class STBDATA {
public:
    size_t row_count;
    size_t col_count;
    std::vector<std::string> data;

public:
    STBDATA();

    bool load(const std::filesystem::path& path);
    bool load(Rose::IO::BinaryReader&& buffer);

    const std::string& value(size_t row_idx, size_t col_idx) const;
    bool set_value(size_t row_idx, size_t col_idx, std::string_view val);

    // Helper functions that converts the value
    char* get_cstr(size_t row_idx, size_t col_idx);
    int16_t get_int16(size_t row_idx, size_t col_idx);
    int32_t get_int32(size_t row_idx, size_t col_idx);

    bool set_cstr(size_t row_idx, size_t col_idx, const char* val);
    bool set_int32(size_t row_idx, size_t col_idx, int32_t val);
};

constexpr const char* ARMS_STB = "3ddata/stb/list_arms.stb";
constexpr const char* BACK_STB = "3ddata/stb/list_back.stb";
constexpr const char* BODY_STB = "3ddata/stb/list_body.stb";
constexpr const char* CAP_STB = "3ddata/stb/list_cap.stb";
constexpr const char* CAMERA_STB = "3ddata/stb/list_camera.stb";
constexpr const char* CLASS_STB = "3ddata/stb/list_class.stb";
constexpr const char* EFFECT_STB = "3ddata/stb/list_effect.stb";
constexpr const char* EVENT_STB = "3ddata/stb/list_event.stb";
constexpr const char* EVENT_BUTTON_STB = "3ddata/stb/eventbutton.stb";
constexpr const char* FACE_STB = "3ddata/stb/list_face.stb";
constexpr const char* FACE_ITEM_STB = "3ddata/stb/list_faceitem.stb";
constexpr const char* FOOT_STB = "3ddata/stb/list_foot.stb";
constexpr const char* GRADE_STB = "3ddata/stb/list_grade.stb";
constexpr const char* HAIR_STB = "3ddata/stb/list_hair.stb";
constexpr const char* HELP_STB = "3ddata/stb/help.stb";
constexpr const char* HELP_LIST_STB = "3ddata/stb/list_help.stb";
constexpr const char* HIT_SOUND_STB = "3ddata/stb/list_hitsound.stb";
constexpr const char* ITEM_DROP_STB = "3ddata/stb/item_drop.stb";
constexpr const char* INIT_AVATAR_STB = "3ddata/stb/init_avatar.stb";
constexpr const char* JEM_ITEM_STB = "3ddata/stb/list_jemitem.stb";
constexpr const char* JEWEL_STB = "3ddata/stb/list_jewel.stb";
constexpr const char* LEVELUP_EVENT_STB = "3ddata/stb/levelupevent.stb";
constexpr const char* MORPH_STB = "3ddata/stb/list_morph_object.stb";
constexpr const char* MOTION_STB = "3ddata/stb/type_motion.stb";
constexpr const char* NATURAL_STB = "3ddata/stb/list_natural.stb";
constexpr const char* NPC_STB = "3ddata/stb/list_npc.stb";
constexpr const char* NPC_FACE_STB = "3ddata/stb/list_npcface.stb";
constexpr const char* PAT_STB = "3ddata/stb/list_pat.stb";
constexpr const char* PAT_SKELETON_STB = "3ddata/stb/list_pat_skeleton.stb";
constexpr const char* PRODUCT_STB = "3ddata/stb/list_product.stb";
constexpr const char* QUEST_ITEM_STB = "3ddata/stb/list_questitem.stb";
constexpr const char* RANGE_SET_STB = "3ddata/stb/rangeset.stb";
constexpr const char* RESOLUTION_STB = "3ddata/stb/resolution.stb";
constexpr const char* SELL_STB = "3ddata/stb/list_sell.stb";
constexpr const char* SKILL_STB = "3ddata/stb/list_skill.stb";
constexpr const char* SKILL_P_STB = "3ddata/stb/list_skill_p.stb";
constexpr const char* SKY_STB = "3ddata/stb/list_sky.stb";
constexpr const char* SOUND_STB = "3ddata/stb/file_sound.stb";
constexpr const char* STATUS_STB = "3ddata/stb/list_status.stb";
constexpr const char* STEP_SOUND_STB = "3ddata/stb/list_stepsound.stb";
constexpr const char* STRING_STB = "3ddata/stb/list_string.stb";
constexpr const char* SUBWPN_STB = "3ddata/stb/list_subwpn.stb";
constexpr const char* TYPE_MOTION_STB = "3ddata/stb/type_motion.stb";
constexpr const char* UNION_STB = "3ddata/stb/list_union.stb";
constexpr const char* USE_ITEM_STB = "3ddata/stb/list_useitem.stb";
constexpr const char* WARP_STB = "3ddata/stb/warp.stb";
constexpr const char* WEAPON_STB = "3ddata/stb/list_weapon.stb";
constexpr const char* ZONE_STB = "3ddata/stb/list_zone.stb";


// list_item.stb
#ifdef __SERVER
    #define ITEM_NAME(T, I) g_pTblSTBs[T]->get_cstr(I, 0)
    #define ITEM_DESC(T, I) g_pTblSTBs[T]->get_cstr(I, g_pTblSTBs[T]->col_count - 1)
#else
    #define ITEM_NAME(T, I) CStringManager::GetSingleton().GetItemName(T, I)
    #define ITEM_DESC(T, I) CStringManager::GetSingleton().GetItemDesc(T, I)
#endif

#define ITEM_ANNOUNCE_TYPE(T, I) g_pTblSTBs[T]->get_int32(I, 2)
#define ITEM_USE_RESTRICTION(T, I) g_pTblSTBs[T]->get_int32(I, 3)

#define ITEM_NO_RESTRICTION 0x00
#define ITEM_DONT_SELL 0x01
#define ITEM_DONT_DROP_EXCHANGE 0x02
#define ITEM_DONT_SELL_DROP_EXCHANGE 0x03
#define ITEM_ENABLE_KEEPING 0x04

#define ITEM_TYPE(T, I) g_pTblSTBs[T]->get_int32(I, 4)
#define ITEM_BASE_PRICE(T, I) g_pTblSTBs[T]->get_int32(I, 5)
#define ITEM_PRICE_RATE(T, I) g_pTblSTBs[T]->get_int32(I, 6)
#define ITEM_WEIGHT(T, I) g_pTblSTBs[T]->get_int32(I, 7)
#define ITEM_QUALITY(T, I) g_pTblSTBs[T]->get_int32(I, 8)
#define ITEM_ICON_NO(T, I) g_pTblSTBs[T]->get_int32(I, 9)
#define ITEM_FIELD_MODEL(T, I) g_pTblSTBs[T]->get_int32(I, 10)
#define ITEM_EQUIP_SOUND(T, I) g_pTblSTBs[T]->get_int32(I, 11)
#define ITEM_MAKE_NUM(T, I) g_pTblSTBs[T]->get_int32(I, 12)
#define ITEM_SKILL_LEV(T, I) g_pTblSTBs[T]->get_int32(I, 13)
#define ITEM_PRODUCT_IDX(T, I) g_pTblSTBs[T]->get_int32(I, 14)
#define ITEM_MAKE_DIFFICULT(T, I) g_pTblSTBs[T]->get_int32(I, 15)
#define ITEM_TRADE_UNIONPOINT(T, I) ITEM_MAKE_DIFFICULT(T, I)

#define ITEM_RATE_TYPE(T, I) g_pTblSTBs[T]->get_int32(I, 16)

#define ITEM_EQUIP_REQUIRE_CLASS(T, I) g_pTblSTBs[T]->get_int32(I, 16)
#define ITEM_EQUIP_REQUIRE_UNION_CNT 2
#define ITEM_EQUIP_REQUIRE_UNION(T, I, C) g_pTblSTBs[T]->get_int32(I, 17 + C)

#define ITEM_NEED_DATA_CNT 2
#define ITEM_NEED_DATA_TYPE(T, I, C) g_pTblSTBs[T]->get_int32(I, 19 + (C * 2))
#define ITEM_NEED_DATA_VALUE(T, I, C) g_pTblSTBs[T]->get_int32(I, 20 + (C * 2))
#define ITEM_NEED_UNION_CNT 2
#define ITEM_NEED_UNION(T, I, C) g_pTblSTBs[T]->get_int32(I, 23 + (C * 3))
#define ITEM_ADD_DATA_TYPE(T, I, C) g_pTblSTBs[T]->get_int32(I, 24 + (C * 3))
#define ITEM_ADD_DATA_VALUE(T, I, C) g_pTblSTBs[T]->get_int32(I, 25 + (C * 3))
#define ITEM_DURABITY(T, I) g_pTblSTBs[T]->get_int32(I, 29)

#define ITEM_RARE_TYPE(T, I) g_pTblSTBs[T]->get_int32(I, 30)
#define ITEM_DEFENCE(T, I) g_pTblSTBs[T]->get_int32(I, 31)
#define ITEM_RESISTENCE(T, I) g_pTblSTBs[T]->get_int32(I, 32)

// list_cap.stb
#define HELMET_NAME(I) ITEM_NAME(ITEM_TYPE_HELMET, I)
#define HELMET_HAIR_TYPE(I) g_TblHELMET.get_int32(I, 33)

// list_body.stb
#define ARMOR_NAME(I) ITEM_NAME(ITEM_TYPE_ARMOR, I)
#define ARMOR_MAT_TYPE(I) g_TblARMOR.get_int32(I, 33)

// list_foot.stb
#define BOOTS_NAME(I) ITEM_NAME(ITEM_TYPE_BOOTS, I)
#define BOOTS_MOVE_SPEED(I) g_TblBOOTS.get_int32(I, 33)

// list_arms.stb
#define GAUNTLET_NAME(I) ITEM_NAME(ITEM_TYPE_GAUNTLET, I)

// list_face.stb
#define FACEITEM_NAME(I) ITEM_NAME(ITEM_TYPE_FACE_ITEM, I)
#define FACEITEM_DESC(I) ITEM_DESC(ITEM_TYPE_FACE_ITEM, I)

// list_back.stb
#define BACKITEM_NAME(I) ITEM_NAME(ITEM_TYPE_KNAPSACK, I)
#define BACKITEM_DESC(I) ITEM_DESC(ITEM_TYPE_KNAPSACK, I)

#define BACKITEM_MOVE_SPEED(I) g_TblBACKITEM.get_int32(I, 33)

// list_Weapon.stb
#define WEAPON_NAME(I) ITEM_NAME(ITEM_TYPE_WEAPON, I)

#define WEAPON_TYPE(I) g_TblWEAPON.get_int32(I, 4)
#define WEAPON_GEM_COUNT(I) g_TblWEAPON.get_int32(I, 5 + 25)

#define WEAPON_ATTACK_RANGE(I) g_TblWEAPON.get_int32(I, 5 + 28)
#define WEAPON_MOTION_TYPE(I) g_TblWEAPON.get_int32(I, 5 + 29)
#define WEAPON_ATTACK_POWER(I) g_TblWEAPON.get_int32(I, 5 + 30)
#define WEAPON_ATTACK_SPEED(I) g_TblWEAPON.get_int32(I, 5 + 31)
#define WEAPON_IS_MAGIC_DAMAGE(I) g_TblWEAPON.get_int32(I, 5 + 32)
#define WEAPON_BULLET_EFFECT(I) g_TblWEAPON.get_int32(I, 5 + 33)
#define WEAPON_DEFAULT_EFFECT(I) g_TblWEAPON.get_int32(I, 5 + 34)
#define WEAPON_ATK_START_SOUND(I) g_TblWEAPON.get_int32(I, 5 + 35)
#define WEAPON_ATK_FIRE_SOUND(I) g_TblWEAPON.get_int32(I, 5 + 36)
#define WEAPON_ATK_HIT_SOUND(I) g_TblWEAPON.get_int32(I, 5 + 37)
#define WEAPON_GEMMING_POSITION(I) g_TblWEAPON.get_int32(I, 43)

// list_subwpn.stb
#define SUBWPN_NAME(I) ITEM_NAME(ITEM_TYPE_SUBWPN, I)
#define SUBWPN_TYPE(I) g_TblSUBWPN.get_int32(I, 4)

#define SUBWPN_GEM_COUNT(I) g_TblSUBWPN.get_int32(I, 5 + 25)
#define SUBWPN_GEMMING_POSITION(I) g_TblSUBWPN.get_int32(I, 34)

// list_jewel.stb
#define JEWEL_NAME(I) ITEM_NAME(ITEM_TYPE_JEWEL, I)

#define JEWEL_ADD_JOB
#define JEWEL_ICON_NO(I) g_TblJEWELITEM.get_int32(I, 9)
#define JEWEL_QUALITY(I) g_TblJEWELITEM.get_int32(I, 8)

#define JEWEL_NEED_DATA_TYPE(I) g_TblJEWELITEM.get_int32(I, 19)
#define JEWEL_NEED_DATA_VALUE(I) g_TblJEWELITEM.get_int32(I, 20)

#define JEWEL_NEED_UNION(I, C) g_TblJEWELITEM.get_int32(I, 23 + (C * 3))
#define JEWEL_ADD_DATA_TYPE(I, C) g_TblJEWELITEM.get_int32(I, 24 + (C * 3))
#define JEWEL_ADD_DATA_VALUE(I, C) g_TblJEWELITEM.get_int32(I, 25 + (C * 3))

// list_useitem.stb
#define USEITEM_NAME(I) ITEM_NAME(ITEM_TYPE_USE, I)
#define USEITEM_DESC(I) ITEM_DESC(ITEM_TYPE_USE, I)

#define USEITEM_STORE_SKIN(I) g_TblUSEITEM.get_int32(I, 8)

#define USEITEM_CONFILE_IDX(I) g_TblUSEITEM.get_int32(I, 22)

#define USEITEM_NEED_DATA_TYPE(I) g_TblUSEITEM.get_int32(I, 17)
#define USEITEM_NEED_DATA_VALUE(I) g_TblUSEITEM.get_int32(I, 18)
#define USEITEM_ADD_DATA_TYPE(I) g_TblUSEITEM.get_int32(I, 19)
#define USEITEM_ADD_DATA_VALUE(I) g_TblUSEITEM.get_int32(I, 20)

#define USEITEM_SCROLL_LEARN_SKILL USEITEM_ADD_DATA_VALUE
#define USEITEM_SCROLL_USE_SKILL USEITEM_ADD_DATA_VALUE

#define USEITEM_SCRIPT(I) g_TblUSEITEM.get_int32(I, 21)
#define USEITEM_USE_EFFECT(I) g_TblUSEITEM.get_int32(I, 22)
#define USEITEM_USE_SOUND(I) g_TblUSEITEM.get_int32(I, 23)
#define USEITME_STATUS_STB(I) g_TblUSEITEM.get_int32(I, 24)

#define USEITME_DELAYTIME_TYPE(I) g_TblUSEITEM.get_int32(I, 25)
#define USEITME_DELAYTIME_TICK(I) g_TblUSEITEM.get_int32(I, 26)
#define USEITEM_COOLTIME_TYPE(I) g_TblUSEITEM.get_int32(I, 25)
#define USEITEM_COOLTIME_DELAY(I) g_TblUSEITEM.get_int32(I, 26)
#define SET_USEITEM_COOLTIME_TYPE(I, V) g_TblUSEITEM.set_int32(I, 25, V)
#define SET_USEITEM_COOLTIME_DELAY(I, V) g_TblUSEITEM.set_int32(I, 26, V)

#define MAX_USEITEM_COOLTIME_TYPE 4

// list_jemitem.stb
#define GEMITEM_NAME(I) ITEM_NAME(ITEM_TYPE_GEM, I)
#define GEMITEM_DESC(I) ITEM_DESC(ITEM_TYPE_GEM, I)

#define GEMITEM_BASE_PRICE(I) g_TblGEMITEM.get_int32(I, 5)
#define GEMITEM_PRICE_RATE(I) g_TblGEMITEM.get_int32(I, 6)

#define GEMITEM_ADD_DATA_TYPE(I, C) g_TblGEMITEM.get_int32(I, 16 + (C * 2))
#define GEMITEM_ADD_DATA_VALUE(I, C) g_TblGEMITEM.get_int32(I, 17 + (C * 2))

#define GEMITEM_MARK_IMAGE(I) g_TblGEMITEM.get_int32(I, 20)
#define GEMITEM_ATTACK_EFFECT(I) g_TblGEMITEM.get_int32(I, 21)

// list_natural.stb
#define NATURAL_NAME(I) ITEM_NAME(ITEM_TYPE_NATURAL, I)
#define NATURAL_DESC(I) ITEM_DESC(ITEM_TYPE_NATURAL, I)
#define NATURAL_BULLET_NO(I) g_TblNATUAL.get_int32(I, 17)

// list_npc.stb
#ifdef __SERVER
    #define NPC_NAME_STR_COLUMN 0

    #define NPC_NAME(I) g_TblNPC.get_cstr(I, NPC_NAME_STR_COLUMN)
    #define NPC_DEAD_EVENT(I) g_TblNPC.get_cstr(I, 41)

    #define SET_NPC_LEVEL(I, V) g_TblNPC.set_int32(I, 7, V)
    #define SET_NPC_ATK_SPEED(I, V) g_TblNPC.set_int32(I, 14, V)
    #define SET_NPC_DROP_TYPE(I, V) g_TblNPC.set_int32(I, 18, V)
    #define SET_NPC_DEAD_EVENT(I, V) g_TblNPC.set_cstr(I, 41, V)
#else
    /// use load2 function
    #define NPC_NAME(I) CStringManager::GetSingleton().GetNpcName(I) 
    #define NPC_DESC(I) g_TblNPC.get_cstr(I, 41)
    #define NPC_HEIGHT(I) g_TblNPC.get_int32(I, 42)
#endif
#define NPC_WALK_SPEED(I) g_TblNPC.get_int32(I, 2)
#define NPC_RUN_SPEED(I) g_TblNPC.get_int32(I, 3)
#define NPC_SCALE(I) g_TblNPC.get_int32(I, 4)
#define NPC_R_WEAPON(I) g_TblNPC.get_int32(I, 5)
#define NPC_L_WEAPON(I) g_TblNPC.get_int32(I, 6)
#define NPC_LEVEL(I) g_TblNPC.get_int32(I, 7)
#define NPC_HP(I) g_TblNPC.get_int32(I, 8)
#define NPC_ATK(I) g_TblNPC.get_int32(I, 9)
#define NPC_HIT(I) g_TblNPC.get_int32(I, 10)
#define NPC_DEF(I) g_TblNPC.get_int32(I, 11)
#define NPC_RES(I) g_TblNPC.get_int32(I, 12)
#define NPC_AVOID(I) g_TblNPC.get_int32(I, 13)
#define NPC_ATK_SPEED(I) g_TblNPC.get_int32(I, 14)
#define NPC_IS_MAGIC_DAMAGE(I) g_TblNPC.get_int32(I, 15)
#define NPC_AI_TYPE(I) g_TblNPC.get_int32(I, 16)
#define NPC_GIVE_EXP(I) g_TblNPC.get_int32(I, 17)
#define NPC_DROP_TYPE(I) g_TblNPC.get_int32(I, 18)
#define NPC_MARK_NO(I) NPC_DROP_TYPE(I)

#define NPC_DROP_MONEY(I) g_TblNPC.get_int32(I, 19)
#define NPC_DROP_ITEM(I) g_TblNPC.get_int32(I, 20)

#define NPC_UNION_NO(I) NPC_DROP_ITEM(I)

#define NPC_NEED_SUMMON_CNT(I) g_TblNPC.get_int32(I, 21)
#define NPC_SELL_TAB(I, T) g_TblNPC.get_int32(I, 21 + T)
#define NPC_SELL_TAB0(I) g_TblNPC.get_int32(I, 21)
#define NPC_SELL_TAB1(I) g_TblNPC.get_int32(I, 22)
#define NPC_SELL_TAB2(I) g_TblNPC.get_int32(I, 23)
#define NPC_SELL_TAB3(I) g_TblNPC.get_int32(I, 24)
#define NPC_CAN_TARGET(I) g_TblNPC.get_int32(I, 25)
#define NPC_ATK_RANGE(I) g_TblNPC.get_int32(I, 26)
#define NPC_TYPE(I) g_TblNPC.get_int32(I, 27)
#define NPC_HIT_MATERIAL_TYPE(I) g_TblNPC.get_int32(I, 28)
#define NPC_FACE_ICON(I) g_TblNPC.get_int32(I, 29)
#define NPC_SUMMONMOB_TYPE(I) g_TblNPC.get_int32(I, 29)
#define NPC_NORMAL_EFFECT_SOUND(I) g_TblNPC.get_int32(I, 30)
#define NPC_ATTACK_SOUND(I) g_TblNPC.get_int32(I, 31)
#define NPC_HITTED_SOUND(I) g_TblNPC.get_int32(I, 32)
#define NPC_HAND_HIT_EFFECT(I) g_TblNPC.get_int32(I, 33)
#define NPC_DEAD_EFFECT(I) g_TblNPC.get_int32(I, 34)
#define NPC_DIE_SOUND(I) g_TblNPC.get_int32(I, 35)

#define NPC_QUEST_TYPE(I) g_TblNPC.get_int32(I, 38)
#define NPC_GLOW_COLOR(I) g_TblNPC.get_int32(I, 39)
#define NPC_STRING_ID(I) g_TblNPC.get_cstr(I, 40)

#define NPC_PVP_STATE(I) g_TblNPC.get_int32(I, 43)

// type_motion.stb
#define FILE_MOTION(WEAPON, ACTION) g_TblAniTYPE.get_int32(ACTION, WEAPON)

// list_effect.stb
#define EFFECT_NAME(I) (NULL)
#define EFFECT_TYPE(I) g_TblEFFECT.get_int32(I, 1)
#define EFFECT_POINT_CNT 4
#define EFFECT_POINT(I, PNO) g_TblEFFECT.get_int32(I, 2 + PNO)
#define EFFECT_POINT1(I) g_TblEFFECT.get_int32(I, 2)
#define EFFECT_POINT2(I) g_TblEFFECT.get_int32(I, 3)
#define EFFECT_POINT3(I) g_TblEFFECT.get_int32(I, 4)
#define EFFECT_POINT4(I) g_TblEFFECT.get_int32(I, 5)
#define EFFECT_TRAIL_NORMAL(I) g_TblEFFECT.get_int32(I, 6)
#define EFFECT_TRAIL_CRITICAL(I) g_TblEFFECT.get_int32(I, 7)
#define EFFECT_TRAIL_DURATION(I) g_TblEFFECT.get_int32(I, 8)
#define EFFECT_HITTED_NORMAL(I) g_TblEFFECT.get_int32(I, 9)
#define EFFECT_HITTED_CRITICAL(I) g_TblEFFECT.get_int32(I, 10)
#define EFFECT_BULLET_NORMAL(I) g_TblEFFECT.get_int32(I, 11)
#define EFFECT_BULLET_CRITICAL(I) g_TblEFFECT.get_int32(I, 12)
#define EFFECT_BULLET_MOVETYPE(I) g_TblEFFECT.get_int32(I, 13)
#define EFFECT_BULLET_TYPE(I) g_TblEFFECT.get_int32(I, 14)
#define EFFECT_BULLET_SPEED(I) g_TblEFFECT.get_int32(I, 15)
#define EFFECT_FIRE_SND_IDX(I) g_TblEFFECT.get_int32(I, 16)
#define EFFFCT_HIT_SND_IDX(I) g_TblEFFECT.get_int32(I, 17)

// item_drop.stb
#define DROPITEM_ITEMNO(I, NO) g_TblDropITEM.get_int32(I, 1 + NO)
#define SET_DROPITEM_ITEMNO(I, NO, V) g_TblDropITEM.set_int32(I, 1 + NO, V)
#define DROPITEM_ITEM1(I) g_TblDropITEM.get_int32(I, 1)

// list_hitsound.stb
#define HIT_SOUND(T, I) g_TblHitSound.get_int32(T, I)

// list_product.stb
#define PRODUCT_TYPE(I) g_TblPRODUCT.get_int32(I, 0)
#define PRODUCT_RAW_MATERIAL(I) g_TblPRODUCT.get_int32(I, 1)

#define PRODUCT_NEED_ITEM_NO(P, C) g_TblPRODUCT.get_int32(P, 2 + (C)*2)
#define PRODUCT_NEED_ITEM_CNT(P, C) g_TblPRODUCT.get_int32(P, 3 + (C)*2)

// list_pat.stb
#define PAT_ITEM_PART_IDX(I) g_PatITEM.get_int32(I, 2)
#define PAT_ITEM_USE_RIGHT(I) g_PatITEM.get_int32(I, 3)
#define PAT_ITEM_TYPE(I) g_PatITEM.get_int32(I, 4)

/*
#define	PAT_ITEM_BASE_PRICE(I) g_PatITEM.get_int32(I, 5)
#define	PAT_ITEM_PRICE_RATE(I) g_PatITEM.get_int32(I, 6)
#define	PAT_ITEM_WEIGHT(I) g_PatITEM.get_int32(I, 7)
#define	PAT_ITEM_QUALITY(I) g_PatITEM.get_int32(I, 8)

#define	PAT_ITEM_ICON_NO(I) g_PatITEM.get_int32(I, 9)
#define	PAT_ITEM_FIELD_IMG(I) g_PatITEM.get_int32(I, 10)
#define	PAT_ITEM_EQUIP_SOUND(I) g_PatITEM.get_int32(I, 11)
*/

#define PAT_ITEM_PART_TYPE(I) g_PatITEM.get_int32(I, 16)
#define PAT_ITEM_PART_VER(I) g_PatITEM.get_int32(I, 17)

#define PAT_ITEM_NEED_SKILL_IDX(I) g_PatITEM.get_int32(I, 19)
#define PAT_ITEM_NEED_SKILL_LEV(I) g_PatITEM.get_int32(I, 20)

#define PAT_ITEM_NEED_ABILITY_IDX(I) g_PatITEM.get_int32(I, 21)
#define PAT_ITEM_NEED_ABILITY_VALUE(I) g_PatITEM.get_int32(I, 22)

#define PAT_ITEM_ADD_ABILITY_CNT 2
#define PAT_ITEM_ADD_ABILITY_IDX(I, C) g_PatITEM.get_int32(I, 24 + C * 3)
#define PAT_ITEM_ADD_ABILITY_VALUE(I, C) g_PatITEM.get_int32(I, 25 + C * 3)

#define PAT_ITEM_MAX_FUEL(I) g_PatITEM.get_int32(I, 31)
#define PAT_ITEM_USE_FUEL_RATE(I) g_PatITEM.get_int32(I, 32)

#define PAT_ITEM_MOV_SPD(I) g_PatITEM.get_int32(I, 33)

#define PAT_ITEM_ATK_RANGE(I) g_PatITEM.get_int32(I, 35)
#define PAT_ITEM_ATK_POW(I) g_PatITEM.get_int32(I, 36)
#define PAT_ITEM_ATK_SPD(I) g_PatITEM.get_int32(I, 37)

#define PAT_ITEM_SEAT_CNT(I) g_PatITEM.get_int32(I, 39)

#define PAT_RELATIVE_MOTION_POS(I) g_PatITEM.get_int32(I, 40)
#define PAT_RELATIVE_MOTION_POS_AVATAR(I) g_PatITEM.get_int32(I, 41)

#define PAT_RIDE_EFFECT(I) g_PatITEM.get_int32(I, 42)
#define PAT_RIDE_SOUND(I) g_PatITEM.get_int32(I, 43)
#define PAT_GETOFF_EFFECT(I) g_PatITEM.get_int32(I, 44)
#define PAT_GETOFF_SOUND(I) g_PatITEM.get_int32(I, 45)
#define PAT_DEAD_EFFECT(I) g_PatITEM.get_int32(I, 46)
#define PAT_DEAD_SOUND(I) g_PatITEM.get_int32(I, 47)
#define PAT_STOP_SOUND(I) g_PatITEM.get_int32(I, 48)
#define PAT_MOVE_EFFECT(I) g_PatITEM.get_int32(I, 49)
#define PAT_MOVE_SOUND(I) g_PatITEM.get_int32(I, 50)

#define PAT_ATTACK_EFFECT(I) g_PatITEM.get_int32(I, 51)
#define PAT_ATTACK_SOUND(I) g_PatITEM.get_int32(I, 52)
#define PAT_HIT_EFFECT(I) g_PatITEM.get_int32(I, 53)
#define PAT_HIT_SOUND(I) g_PatITEM.get_int32(I, 54)

#define PAT_BULLET(I) g_PatITEM.get_int32(I, 55)
#define PAT_BULLET_FIRE_POINT(l, m) g_PatITEM.get_int32(l, m)

#define PAT_ITEM_ATTACHED_EFFECT_CNT 8
#define PAT_ITEM_ATTACHED_EFFECT(I, T) g_PatITEM.get_int32(I, 56 + T)

#define PAT_ITEM_CART_GAUAGE(I) g_PatITEM.get_int32(I, 64)
#define PAT_ITEM_EQUIP_REQUIRE_CLASS(I) g_PatITEM.get_int32(I, 65)
#define PAT_ITEM_ABILITY_TYPE(I) g_PatITEM.get_int32(I, 66)

#define PAT_ATTACH_NODE(I) g_PatITEM.get_int32(I, 67)
#define PAT_SCALE(I) g_PatITEM.get_int32(I, 68)

#ifdef __KCHS_BATTLECART__
    #define PAT_ITEM_HP(I) g_PatITEM.get_int32(I, 67)
    #define PAT_ITEM_EQUIP_REQUIRE_CLASS(I) g_PatITEM.get_int32(I, 68)
    #define PAT_DAMAGE_TYPE(I) g_PatITEM.get_int32(I, 69)
    #define PAT_ABILITY_TYPE(I) g_PatITEM.get_int32(I, 70)
#endif

// list_sell.stb
#ifdef __SERVER
    #define STORE_NAME(I) g_TblStore.get_cstr(I, 0)
#else
    #define STORE_NAME(I) CStringManager::GetSingleton().GetStoreTabName(I)
#endif
#define STORE_ITEM(I, T) g_TblStore.get_int32(I, 2 + T)

// warp.stb
#define TELEPORT_NAME(I) g_TblWARP.get_cstr(I, 0)
#define TELEPORT_ZONE(I) g_TblWARP.get_int32(I, 1)
#define TELEPORT_EVENT_POS(I) g_TblWARP.get_cstr(I, 2)

// list_event.stb
#define EVENT_NAME(I) g_TblEVENT.get_cstr(I, 0)
#define EVENT_TYPE(I) g_TblEVENT.get_cstr(I, 1)
#define EVENT_DESC(I) g_TblEVENT.get_cstr(I, 2)
#define EVENT_FILENAME(I) g_TblEVENT.get_cstr(I, 3)

// list_sky.stb
#define SKY_MESH(S) g_TblSKY.get_cstr(S, 0)
#define SKY_TEXTURE_CNT 4
#define SKY_TEXTURE(S, T) g_TblSKY.get_cstr(S, 1 + T)
#define SKY_LIGHTMAP_BLEND(I) g_TblSKY.get_int32(I, 5)
#define SKY_AMBIENT_CNT 4
#define SKY_AMBIENT(S, T) g_TblSKY.get_int32(S, 6 + T)
#define SKY_CHAR_LIGHT_CNT 4
#define SKY_CHAR_AMBIENT(S, T) g_TblSKY.get_int32(S, 10 + (2 * T))
#define SKY_CHAR_DIFFUSE(S, T) g_TblSKY.get_int32(S, 10 + (2 * T) + 1)

#define SKY_CHANGE_DELAY_CNT 4
#define SKY_CHANGE_DELAY(I, T) g_TblSKY.get_int32(I, 18 + T)

// list_zone.stb
#ifdef __SERVER
    #define ZONE_NAME(I) g_TblZONE.get_cstr(I, 0)
    #define ZONE_DESC(I)
#else
    #define ZONE_NAME(I) CStringManager::GetSingleton().GetZoneName(I)
    #define ZONE_DESC(I) CStringManager::GetSingleton().GetZoneDesc(I)
#endif

#define ZONE_FILE(I) g_TblZONE.get_cstr(I, 1)
#define ZONE_START_POS(I) g_TblZONE.get_cstr(I, 2)
#define ZONE_REVIVE_POS(I) g_TblZONE.get_cstr(I, 3)
#define ZONE_IS_UNDERGROUND(I) g_TblZONE.get_int32(I, 4)
#define ZONE_BG_MUSIC_DAY(I) g_TblZONE.get_cstr(I, 5)

#define ZONE_BG_MUSIC_NIGHT(I) g_TblZONE.get_cstr(I, 6)
#define ZONE_BG_IMAGE(I) g_TblZONE.get_int32(I, 7)
#define ZONE_MINIMAP_NAME(I) g_TblZONE.get_cstr(I, 8)
#define ZONE_MINIMAP_STARTX(I) g_TblZONE.get_int32(I, 9)
#define ZONE_MINIMAP_STARTY(I) g_TblZONE.get_int32(I, 10)

#define ZONE_OBJECT_TABLE(I) g_TblZONE.get_cstr(I, 11)
#define ZONE_CNST_TABLE(I) g_TblZONE.get_cstr(I, 12)
#define ZONE_DAY_CYCLE(I) g_TblZONE.get_int32(I, 13)
#define ZONE_MORNING_TIME(I) g_TblZONE.get_int32(I, 14)
#define ZONE_DAY_TIME(I) g_TblZONE.get_int32(I, 15)

#define ZONE_EVENING_TIME(I) g_TblZONE.get_int32(I, 16)
#define ZONE_NIGHT_TIME(I) g_TblZONE.get_int32(I, 17)
#define ZONE_PVP_STATE(I) g_TblZONE.get_int32(I, 18)
#define ZONE_PLANET_NO(I) g_TblZONE.get_int32(I, 19)
#define ZONE_TYPE(I) g_TblZONE.get_int32(I, 20)

#define ZONE_CAMERA_TYPE(I) g_TblZONE.get_int32(I, 21)
#define ZONE_JOIN_TRIGGER(I) g_TblZONE.get_cstr(I, 22)
#define ZONE_KILL_TRIGGER(I) g_TblZONE.get_cstr(I, 23)
#define ZONE_DEAD_TRIGGER(I) g_TblZONE.get_cstr(I, 24)
#define ZONE_SECTOR_SIZE(I) g_TblZONE.get_int32(I, 25)

#define ZONE_STRING_ID(I) g_TblZONE.get_cstr(I, 26)
#define ZONE_WEATHER_TYPE(I) g_TblZONE.get_int32(I, 27)
#define ZONE_PARTY_EXP_A(I) g_TblZONE.get_int32(I, 28)
#define ZONE_PARTY_EXP_B(I) g_TblZONE.get_int32(I, 29)
#define ZONE_RIDING_REFUSE_FLAG(I) g_TblZONE.get_int32(I, 30)
//#define	ZONE_OCEAN_TEXTURE_DIRECTORY(I)		g_TblZONE.get_int32( I ,  30 )
//#define	ZONE_OCEAN_FRAME(I)					g_TblZONE.get_int32( I ,  31 )

#define ZONE_REVIVE_ZONENO(I) g_TblZONE.get_int32(I, 31)
#define ZONE_REVIVE_X_POS(I) g_TblZONE.get_int32(I, 32)
#define ZONE_REVIVE_Y_POS(I) g_TblZONE.get_int32(I, 33)

// init_avatar.stb
#define AVATAR_STR(I) g_TblAVATAR.get_int32(I, 0)
#define AVATAR_DEX(I) g_TblAVATAR.get_int32(I, 1)
#define AVATAR_INT(I) g_TblAVATAR.get_int32(I, 2)
#define AVATAR_CON(I) g_TblAVATAR.get_int32(I, 3)
#define AVATAR_CHARM(I) g_TblAVATAR.get_int32(I, 4)
#define AVATAR_SENSE(I) g_TblAVATAR.get_int32(I, 5)

#define AVATAR_FACEITEM(I) g_TblAVATAR.get_int32(I, 6)
#define AVATAR_HELMET(I) g_TblAVATAR.get_int32(I, 7)
#define AVATAR_ARMOR(I) g_TblAVATAR.get_int32(I, 8)
#define AVATAR_GAUNTLET(I) g_TblAVATAR.get_int32(I, 9)
#define AVATAR_BOOTS(I) g_TblAVATAR.get_int32(I, 10)
#define AVATAR_BACKITEM(I) g_TblAVATAR.get_int32(I, 11)
#define AVATAR_WEAPON(I) g_TblAVATAR.get_int32(I, 12)
#define AVATAR_SUBWPN(I) g_TblAVATAR.get_int32(I, 13)

#define AVATAR_ITEM_WEAPON(I, J) g_TblAVATAR.get_int32(I, 14 + J)
#define AVATAR_ITEM_USE(I, J) g_TblAVATAR.get_int32(I, 24 + (J)*2)
#define AVATAR_ITEM_USECNT(I, J) g_TblAVATAR.get_int32(I, 25 + (J)*2)
#define AVATAR_ITEM_ETC(I, J) g_TblAVATAR.get_int32(I, 34 + (J)*2)
#define AVATAR_ITEM_ETCCNT(I, J) g_TblAVATAR.get_int32(I, 35 + (J)*2)

#define AVATAR_MONEY(I) g_TblAVATAR.get_int32(I, 44)
#define AVATAR_ZONE(I) g_TblAVATAR.get_int32(I, 45)

/// resolution.stb
#define RESOLUTION_DEFAULT 0
#define RESOLUTION_NAME(I) g_TblResolution.get_cstr(I, 0)
#define RESOLUTION_WIDTH(I) g_TblResolution.get_int32(I, 1);
#define RESOLUTION_HEIGHT(I) g_TblResolution.get_int32(I, 2);
#define RESOLUTION_DEPTH(I) g_TblResolution.get_int32(I, 3);

/// list_status.stb
#ifdef __SERVER
    #define STATE_NAME(I) g_TblSTATE.get_cstr(I, 0)
#else
    #define STATE_NAME(I) CStringManager::GetSingleton().GetStatusName(I)
#endif

#define STATE_TYPE(I) g_TblSTATE.get_int32(I, 1)
#define STATE_CAN_DUPLICATED(I) g_TblSTATE.get_int32(I, 2)
#define STATE_PRIFITS_LOSSES(I) g_TblSTATE.get_int32(I, 3)
#define STATE_APPLY_ARG(I) g_TblSTATE.get_int32(I, 4)

#define STATE_APPLY_ABILITY_CNT 2
#define STATE_APPLY_ING_STB(I, T) g_TblSTATE.get_int32(I, 5 + (T)*2)
#define STATE_APPLY_ABILITY_VALUE(I, T) g_TblSTATE.get_int32(I, 5 + (T)*2 + 1)

#define STATE_SYMBOL(I) g_TblSTATE.get_int32(I, 9)
#define STATE_STEP_EFFECT(I) g_TblSTATE.get_int32(I, 10)
#define STATE_STEP_SOUND(I) g_TblSTATE.get_int32(I, 11)

#define STATE_CONTROL_CNT 3
#define STATE_CONTROL(I, T) g_TblSTATE.get_int32(I, 12 + (T))

#define STATE_SHOTDOWN_EFFECT(I) g_TblSTATE.get_int32(I, 15)
#define STATE_SHOTDOWN_SOUND(I) g_TblSTATE.get_int32(I, 16)

#define STATE_PRIFITS_LOSSES_BY_STATE(I) g_TblSTATE.get_int32(I, 17)

#ifdef __SERVER
    #define STATE_SETTING_STRING(I) g_TblSTATE.get_cstr(I, 18)
    #define STATE_DELETE_STRING(I) g_TblSTATE.get_cstr(I, 19)
#else
    #define STATE_SETTING_STRING(I) CStringManager::GetSingleton().GetStatusStartMsg(I)
    #define STATE_DELETE_STRING(I) CStringManager::GetSingleton().GetStatusEndMsg(I)
#endif

#define STATE_STRING_ID(I) g_TblSTATE.get_cstr(I, 20)

// rangeset.stb
#define LOD_APPEAR_MIN(I) g_TblRangeSet.get_int32(I, 1)
#define LOD_APPEAR_MAX(I) g_TblRangeSet.get_int32(I, 2)

// list_union.stb
#ifdef __SERVER
    #define UNION_NAME(I) g_TblUnion.get_cstr(I, 0)
#else
    #define UNION_NAME(I) CStringManager::GetSingleton().GetUnionName(I)
#endif
#define UNION_COLOR(I) g_TblUnion.get_int32(I, 1)
#define UNION_MARK(I) g_TblUnion.get_int32(I, 2)
#define UNION_HOSTILE_CNT 6
#define UNION_HOSTILE(I, C) g_TblUnion.get_int32(I, 3 + C)
#define UNION_STRING_ID(I) g_TblUnion.get_cstr(I, 11)

// list_class.stb
#ifdef __SERVER
    #define CLASS_NAME(I) g_TblClass.c_str(I, 0)
#else
    #define CLASS_NAME(I) CStringManager::GetSingleton().GetClassName(I)
#endif
#define CLASS_INCLUDE_JOB_CNT 8
#define CLASS_INCLUDE_JOB(I, C) g_TblClass.get_int32(I, 1 + C)
#define CLASS_STRING_ID(L) g_TblClass.get_cstr(L, 11)

// list_stepsound.stb
#define STEPSOUND(ZONETYPE, TILENO) g_TblStepSound.get_int32(TILENO, ZONETYPE)

// list_grade.stb
#define ITEMGRADE_ATK(G) g_TblItemGRADE.get_int32(G, 0)
#define ITEMGRADE_HIT(G) g_TblItemGRADE.get_int32(G, 1)
#define ITEMGRADE_DEF(G) g_TblItemGRADE.get_int32(G, 2)
#define ITEMGRADE_RES(G) g_TblItemGRADE.get_int32(G, 3)
#define ITEMGRADE_AVOID(G) g_TblItemGRADE.get_int32(G, 4)
#define ITEMGRADE_GLOW_COLOR(G) g_TblItemGRADE.get_int32(G, 5)

// list_camera.stb
#define CAMERA_NAME(I) g_TblCamera.get_cstr(I, 0)
#define CAMERA_ZSC_FILE(I) g_TblCamera.get_cstr(I, 1)
#define CAMERA_FOV(I) g_TblCamera.get_int32(I, 2)
#define CAMERA_ASPECT_RATIO(I) g_TblCamera.get_cstr(I, 3)
#define CAMERA_MAX_RANGE(I) g_TblCamera.get_int32(I, 4)
#define CAMERA_NEAR_PLANE(I) g_TblCamera.get_int32(I, 5)
#define CAMERA_FAR_PLANE(I) g_TblCamera.get_int32(I, 6)
#define CAMERA_NEAR_ALPHA_FOG(I) g_TblCamera.get_int32(I, 7)
#define CAMERA_FAR_ALPHA_FOG(I) g_TblCamera.get_int32(I, 8)
#define CAMERA_NEAR_FOG(I) g_TblCamera.get_int32(I, 9)
#define CAMERA_FAR_FOG(I) g_TblCamera.get_int32(I, 10)

extern STBDATA g_TblHAIR;
extern STBDATA g_TblFACE;

extern STBDATA g_TblARMOR;
extern STBDATA g_TblGAUNTLET;
extern STBDATA g_TblBOOTS;
extern STBDATA g_TblHELMET;
extern STBDATA g_TblWEAPON;
extern STBDATA g_TblSUBWPN;
extern STBDATA g_TblFACEITEM;
extern STBDATA g_TblBACKITEM;
extern STBDATA g_TblJEWELITEM;
extern STBDATA g_TblGEMITEM;
extern STBDATA g_TblNATUAL;
extern STBDATA g_TblUSEITEM;

extern STBDATA g_TblEFFECT;
extern STBDATA g_TblNPC;
extern STBDATA g_TblDropITEM;
extern STBDATA g_TblAniTYPE;
extern STBDATA g_TblPRODUCT;
extern STBDATA g_PatITEM;

extern STBDATA g_TblQUESTITEM;
extern STBDATA g_TblStore;

extern STBDATA g_TblWARP;
extern STBDATA g_TblEVENT;

extern STBDATA g_TblSKY;

extern STBDATA g_TblZONE;

extern STBDATA* g_pTblSTBs[STB_FILE_COUNT + 1];

extern STBDATA g_TblString;
extern STBDATA g_TblHitSound;

extern STBDATA g_TblAVATAR;
extern STBDATA g_TblResolution;

extern STBDATA g_TblSTATE;

extern STBDATA g_TblCamera;
extern STBDATA g_TblRangeSet;

extern STBDATA g_TblUnion;
extern STBDATA g_TblClass;
extern STBDATA g_TblStepSound;

extern STBDATA g_TblItemGRADE;

#ifndef __SERVER
extern STBDATA g_TblHELP;
extern STBDATA g_TblBadNames;
#endif
