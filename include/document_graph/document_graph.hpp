#pragma once

#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/transaction.hpp>
#include <eosio/crypto.hpp>
#include <eosio/multi_index.hpp>
#include <eosio/name.hpp>
#include <cstring>

#include <document_graph/content.hpp>
#include <document_graph/document.hpp>
// #include <document_graph/edge.hpp>

namespace hypha
{
    class DocumentGraph
    {
    public:
        eosio::name m_contract;

        DocumentGraph(const eosio::name &contract) : m_contract(contract){}
        ~DocumentGraph(){}
 
        typedef eosio::multi_index<eosio::name("documents"), Document,
                        eosio::indexed_by<eosio::name("idhash"), eosio::const_mem_fun<Document, eosio::checksum256, &Document::by_hash>>,
                        eosio::indexed_by<eosio::name("bycreator"), eosio::const_mem_fun<Document, uint64_t, &Document::by_creator>>,
                        eosio::indexed_by<eosio::name("bycreated"), eosio::const_mem_fun<Document, uint64_t, &Document::by_created>>>
        document_table;

        // typedef eosio::multi_index<eosio::name("edges"), Edge,
        //     indexed_by<eosio::name("fromnode"), const_mem_fun<Edge, eosio::checksum256, &Edge::by_from>>,
        //     indexed_by<eosio::name("tonode"), const_mem_fun<Edge, eosio::checksum256, &Edge::by_to>>,
        //     indexed_by<eosio::name("edgename"), const_mem_fun<Edge, uint64_t, &Edge::by_edge_name>>,
        //     indexed_by<eosio::name("byfromname"), const_mem_fun<Edge, uint64_t, &Edge::by_from_node_edge_name_index>>,
        //     indexed_by<eosio::name("byfromto"), const_mem_fun<Edge, uint64_t, &Edge::by_from_node_to_node_index>>,
        //     indexed_by<eosio::name("bytoname"), const_mem_fun<Edge, uint64_t, &Edge::by_to_node_edge_name_index>>,
        //     indexed_by<eosio::name("bycreated"), const_mem_fun<Edge, uint64_t, &Edge::by_created>>,
        //     indexed_by<eosio::name("bycreator"), const_mem_fun<Edge, uint64_t, &Edge::by_creator>>>
        // edge_table;

        // void create_edge (const checksum256 &from_node, const checksum256 &to_node, const name &edge_name);
        // void create_edge (const checksum256 &from_node, const checksum256 &to_node, const name &edge_name, const bool strict);

        // void remove_edge (const checksum256 &from_node, const checksum256 &to_node, const name &edge_name, const bool strict);
        // void remove_edges (const checksum256 &from_node, const checksum256 &to_node, const bool strict);
        // void remove_edges (const checksum256 &from_node, const name &edge_name, const bool strict);
        // void remove_edges (const checksum256 &node, const bool strict);

        // vector<edge> get_edges (const checksum256 &from_node, const name &edge_name, const bool strict);
        // vector<edge> get_edges_from_name (const checksum256 &from_node, const name &edge_name, const bool strict);
        // vector<edge> get_edges_to_name (const checksum256 &to_node, const name &edge_name, const bool strict);
        // vector<edge> get_edges_from_to (const checksum256 &from_node, const checksum256 &to_node, const bool strict);

        // edge get_edge (const checksum256 &from_node, const name &edge_name, const bool strict);
        // edge get_edge_from_name (const checksum256 &from_node, const name &edge_name, const bool strict);
        // edge get_edge_to_name (const checksum256 &to_node, const name &edge_name, const bool strict);
        // edge get_edge_from_to (const checksum256 &from_node, const checksum256 &to_node, const bool strict);
        
        // Any account/member can creator a new document, support many options/constructors
        Document createDocument(eosio::name &creator, std::vector<ContentGroup> &contentGroups);
        Document createDocument(eosio::name &creator);
        // Edge createEdge (const eosio::checksum256 &from_node, const eosio::checksum256 &to_node, const eosio::name &edge_name);
        // document create_document(const name &creator, const content_group &content_group);
        // document create_document(const name &creator, const content &content);
        // document create_document(const name &creator, const string &content_label, const flexvalue &content_value);

        // document get_or_create(const name &creator, const vector<content_group> &content_groups);
        // document get_or_create(const name &creator, const content_group &content_group);
        // document get_or_create(const name &creator, const content &content);
        // document get_or_create(const name &creator, const string &content_label, const flexvalue &content_value);

        // void erase_document(const checksum256 &document_hash);
    
        // // Fork creates a new document (node in a graph) from an existing document.
        // // The forked content should contain only new or updated entries to avoid data duplication. (lazily enforced?)
        // document fork_document(const checksum256 &hash, const name &creator, const vector<content_group> &content_groups);
        // document fork_document(const checksum256 &hash, const name &creator, const content &content);

        // // Creates a 'certificate' on a specific fork.
        // // A certificate can be customized based on the document, but it represents
        // // the signatures, with notes/timestamp, and of course auth is enforced
        // void certify_document(const name &certifier, const checksum256 &hash, const string &notes);

        // certificate new_certificate(const name &certifier, const string &notes);
        // content new_content(const string &label, const flexvalue &fv);

        // // accessors
        // document get_document (const checksum256 &hash);
        // document get_parent (const document &document);
       
        // content_group get_content_group(const vector<content_group> &content_groups, 
        //                                 const string &content_group_label, 
        //                                 const bool &strict);
        
        // content_group get_content_group (const document &document, 
        //                                     const string &content_group_label, 
        //                                     const bool &strict);

        // std::vector<content_group> get_content_groups_of_type(const vector<content_group> &content_groups, 
        //                                         const name &content_group_type,
        //                                         const bool &strict);

        // flexvalue get_content (const content_group &content_group, const string& content_label, const bool &strict);
        // flexvalue get_content(const document &document,
        //                         const string &content_group_label,
        //                         const string &content_label,
        //                         const bool &strict);
        // content get_content_item(const content_group &content_group,
        //                                                         const string &content_label,
        //                                                         const bool &strict);

        // static std::string to_string(const vector<document_graph::content_group> &content_groups);
        // static std::string to_string(const document_graph::content_group &content_group);
        // static std::string to_string(const document_graph::content &content);
        // static std::string to_string(const document_graph::flexvalue &value);

        // static checksum256 hash_document (const vector<content_group> &content_groups);
        // static std::string to_hex(const char *d, uint32_t s);
        // static std::string readable_hash (const checksum256 &proposal_hash);
        
        // // uint64_t to_uint64 (const checksum256 &document_hash);
        // static uint64_t to_uint64 (const string &fingerprint);
        // static uint64_t edge_id(checksum256 from_node, checksum256 to_node, name edge_name);
        // static uint64_t hash(checksum256 from_node, checksum256 to_node);
        // static uint64_t hash(checksum256 from_node, name edge_name); 
    };
}; // namespace hypha


// #define DECLARE_DOCUMENT(contract)\
// using flexvalue = hypha::document_graph::flexvalue;\
// using root_doc = hypha::document_graph::document;\
// TABLE contract##_document : public root_doc {};\
// using contract_document = contract##_document;\
// using document_table =  multi_index<name("documents"), contract_document,\
//                             indexed_by<name("idhash"), const_mem_fun<root_doc, checksum256, &root_doc::by_hash>>,\
//                             indexed_by<name("bycreator"), const_mem_fun<root_doc, uint64_t, &root_doc::by_creator>>,\
//                             indexed_by<name("bycreated"), const_mem_fun<root_doc, uint64_t, &root_doc::by_created>>>;\
// using root_edge = hypha::document_graph::edge;\
// TABLE contract##_edge : public hypha::document_graph::edge {};\
// using contract_edge = contract##_edge;\
// using edge_table = multi_index<name("edges"), contract_edge,\
//             indexed_by<name("fromnode"), const_mem_fun<root_edge, checksum256, &root_edge::by_from>>,\
//             indexed_by<name("tonode"), const_mem_fun<root_edge, checksum256, &root_edge::by_to>>,\
//             indexed_by<name("edgename"), const_mem_fun<root_edge, uint64_t, &root_edge::by_edge_name>>,\
//             indexed_by<name("byfromname"), const_mem_fun<root_edge, uint64_t, &root_edge::by_from_node_edge_name_index>>,\
//             indexed_by<name("byfromto"), const_mem_fun<root_edge, uint64_t, &root_edge::by_from_node_to_node_index>>,\
//             indexed_by<name("bytoname"), const_mem_fun<root_edge, uint64_t, &root_edge::by_to_node_edge_name_index>>,\
//             indexed_by<name("bycreated"), const_mem_fun<root_edge, uint64_t, &root_edge::by_created>>,\
//             indexed_by<name("bycreator"), const_mem_fun<root_edge, uint64_t, &root_edge::by_creator>>>;