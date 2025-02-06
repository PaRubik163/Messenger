#include <QJsonObject>
#include <QString>
#include <exception>

#pragma once

class CheckNameResponse
{
private:
    bool success_;
    QString description_;

public:
    CheckNameResponse& success(bool s)
    {
        success_ = s;
        return *this;
    }

    CheckNameResponse& description(const QString &d)
    {
        description_= d;
        return *this;
    }

    QJsonObject build() const
    {
        QJsonObject obj;
        obj["type"] = "check name response";
        obj["success"] = success_;
        if (!success_)
        {
            if (description_.isEmpty())
                throw std::invalid_argument("description is empty");
            obj["description"] = description_;
            return obj;
        }
        return obj;
    }
};

