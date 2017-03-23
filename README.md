#What it does

The CiviCRM Session Tokens module allows site builders to gain access to a
wide range of variables associated with the currently logged in CiviCRM user.

For example, it provides a token of the user's membership's owner id. It
provides each value for (one active instance of) each membership type, and one
relationship type.

It also allows any token to be allowed as a filter in a view and in a block's contents.

The current use case is to provide a portal that only shows contacts with
relationships to the logged in user's employer. This is done by filtering on:

   contact_a_b = [civicrm_session_tokens:active_relationships_a_employee_of_contact_id_b]

The full list of tokens is included in a watchdog entry upon login. The
relationships and memberships entries are generated based on their types' names:

###In relationships:

If the user is contact_id_a: active_relationships_a_{name in lowercase spaces replaced by underscores}_{key from API get call, i.e. id, relationship_type_id}.
If the user is contact_id_b: active_relationships_b_{name in lowercase spaces replaced by underscores}_{key from API get call, i.e. id, relationship_type_id}.

###In memberships:

active_memberships_{name in lowercase spaces replaced by underscores}_{values from API get call, i.e. id, membership_owner_id}
 
My currently logged in user (active membership of type 'Charity Partner' and active relationship type 'Employee of') has the following tokens:

[civicrm_session_tokens:id] => 2 

[civicrm_session_tokens:domain_id] => 1 

[civicrm_session_tokens:uf_id] => 2 

[civicrm_session_tokens:uf_name] => john+1@civifirst.com 

[civicrm_session_tokens:contact_id] => 4 

[civicrm_session_tokens:active_memberships_charity_partner_id] => 6 

[civicrm_session_tokens:active_memberships_charity_partner_contact_id] => 4 

[civicrm_session_tokens:active_memberships_charity_partner_membership_type_id] => 3 

[civicrm_session_tokens:active_memberships_charity_partner_join_date] => 2017-02-09 

[civicrm_session_tokens:active_memberships_charity_partner_status_id] => 1 

[civicrm_session_tokens:active_memberships_charity_partner_owner_membership_id] => 5 

[civicrm_session_tokens:active_memberships_charity_partner_is_test] => 0 

[civicrm_session_tokens:active_memberships_charity_partner_is_pay_later] => 0 

[civicrm_session_tokens:active_memberships_charity_partner_membership_name] => Charity Partner 

[civicrm_session_tokens:active_memberships_charity_partner_relationship_name] => Employee of 

[civicrm_session_tokens:active_memberships_charity_partner_related_contact_id] => 4 

[civicrm_session_tokens:active_memberships] => Array ( ) 

[civicrm_session_tokens:active_relationships_a_employee_of_id] => 2 

[civicrm_session_tokens:active_relationships_a_employee_of_contact_id_a] => 4 

[civicrm_session_tokens:active_relationships_a_employee_of_contact_id_b] => 3 

[civicrm_session_tokens:active_relationships_a_employee_of_relationship_type_id] => 5 

[civicrm_session_tokens:active_relationships_a_employee_of_is_active] => 1 

[civicrm_session_tokens:active_relationships_a_employee_of_is_permission_a_b] => 0 

[civicrm_session_tokens:active_relationships_a_employee_of_is_permission_b_a] => 0
