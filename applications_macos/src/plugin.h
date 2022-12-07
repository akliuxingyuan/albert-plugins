// Copyright (c) 2022 Manuel Schneider

#pragma once
#include "albert.h"
#include <memory>
#include <QFileSystemWatcher>


class Plugin:
    public albert::ExtensionPlugin,
    public albert::IndexQueryHandler

{
    Q_OBJECT ALBERT_PLUGIN
public:
    Plugin();

    std::vector<albert::IndexItem> indexItems() const override;

protected:
    static std::vector<std::shared_ptr<albert::StandardItem>> indexApps(const bool &abort);
    albert::BackgroundExecutor<std::vector<std::shared_ptr<albert::StandardItem>>> indexer;
    std::vector<std::shared_ptr<albert::StandardItem>> apps;
    QFileSystemWatcher fs_watcher_;
};