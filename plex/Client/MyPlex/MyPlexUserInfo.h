//
//  MyPlexUserInfo.h
//  Plex
//
//  Created by Tobias Hieta <tobias@plexapp.com> on 2013-04-12.
//  Copyright 2013 Plex Inc. All rights reserved.
//

#ifndef MYPLEXUSERINFO_H
#define MYPLEXUSERINFO_H

#include "XBMCTinyXML.h"
#include "XBDateTime.h"
#include <string>


class CMyPlexUserInfo
{
  public:

    enum MyPlexRoles
    {
      ROLE_USER = 0,
      ROLE_EMPLOYEE = 2,
      ROLE_NINJA = 4,
      ROLE_PLEXPASS = 8
    };

    CMyPlexUserInfo() : roles(ROLE_USER), id(-1) {}

    bool SetFromXmlElement(TiXmlElement* root);

    std::string email;
    int id;
    std::string username;
    std::string queueEmail;
    std::string queueUID;
    std::string cloudSyncDevice;
    std::string authToken;

    bool subscription;
    std::string subscriptionStatus;
    std::string subscriptionPlan;
    std::vector<std::string> features;
    CDateTime joinedAt;

    int roles;

    bool hasRole(MyPlexRoles role)
    {
      return (role & roles) == role;
    }

    void operator=(const CMyPlexUserInfo& other)
    {
      email = other.email;
      id = other.id;
      username = other.username;
      queueEmail = other.queueEmail;
      queueUID = other.queueUID;
      cloudSyncDevice = other.cloudSyncDevice;
      authToken = other.authToken;
      subscription = other.subscription;
      subscriptionStatus = other.subscriptionStatus;
      subscriptionPlan = other.subscriptionPlan;
      features = other.features;
      joinedAt = other.joinedAt;
      roles = other.roles;
    }
};

#endif // MYPLEXUSERINFO_H
