#pragma once
#include <eosio/multi_index.hpp>
#include <variant>
#include <eosio/name.hpp>
#include <eosio/asset.hpp>
#include <eosio/transaction.hpp>
#include <eosio/crypto.hpp>

#include <document_graph/content.hpp>
#include <document_graph/content_group.hpp>

namespace hypha
{

    struct [[eosio::table, eosio::contract("docs")]] Document
    {
        Document();
        Document(const uint64_t id, const eosio::name creator, std::vector<ContentGroup> contentGroups);
        ~Document();

        uint64_t primary_key() const { return id; }
        uint64_t by_creator() const { return creator.value; }
        eosio::checksum256 by_hash() const { return hash; }
        uint64_t by_created() const { return created_date.sec_since_epoch(); }
        
        void setCreator(eosio::name & creator);
        eosio::name getCreator();
        eosio::checksum256 getHash();
        std::vector<ContentGroupWrapper> getContentGroups();
        std::pair<int64_t, ContentGroupWrapper *> getContentGroup(const std::string &label);
        ContentGroupWrapper * getContentGroupOrFail(const std::string &label, const std::string &error);
        Content::FlexValue getValueOrFail(const std::string &contentGroupLabel, const std::string &contentLabel, const std::string &error);
        void add(ContentGroup cg);

        // members, with names as serialized - these must be public for EOSIO tables
        std::uint64_t id;
        eosio::checksum256 hash;
        eosio::name creator;
        std::vector<ContentGroup> content_groups;
        eosio::time_point created_date;

        const eosio::checksum256 hash_contents();

        private: 
            const std::string toString();
            const std::string toString(ContentGroup contentGroup);

        EOSLIB_SERIALIZE(Document, (id)(hash)(creator)(content_groups)(created_date))
    };

} // namespace hypha