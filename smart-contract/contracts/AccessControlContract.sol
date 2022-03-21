// // SPDX-License-Identifier: MIT
pragma solidity >=0.4.22 <0.9.0;
contract AccessControlContract 
{

  mapping(string=>mapping(address=>bool)) public hasPermissionsMap;

    function doesUserHavePermission(string memory cid,address userAddress)
        public
        view
        returns (bool)
    {
        return hasPermissionsMap[cid][userAddress];
    }

    function addPermission(string memory cid,address userAddress)
        public
    {
        hasPermissionsMap[cid][userAddress]=true;
    }

    function removePermission(string memory cid,address userAddress)
        public
    {
        hasPermissionsMap[cid][userAddress]=false;
    }
}