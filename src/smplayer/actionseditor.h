/*  smplayer, GUI front-end for mplayer.
    Copyright (C) 2006-2015 Ricardo Villalba <rvm@users.sourceforge.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

/* This is based on qq14-actioneditor-code.zip from Qt */

#ifndef _ACTIONSEDITOR_H_
#define _ACTIONSEDITOR_H_

#include <QWidget>
#include <QList>
#include <QStringList>

class QTableWidget;
class QTableWidgetItem;
class QAction;
class QSettings;
class QPushButton;


class ActionsEditor : public QWidget
{
    Q_OBJECT

public:
    ActionsEditor( QWidget * parent = 0, Qt::WindowFlags f = 0 );
	~ActionsEditor();

	// Clear the actionlist
	void clear();

	// There are no actions yet?
    bool isEmpty();

    void addCurrentActions(QWidget * widget);

	// Static functions
	static QAction * findAction(QObject *o, const QString & name);
	static QStringList actionsNames(QObject *o);

    static void saveToConfig(QObject *o, QSettings *set);
	static void loadFromConfig(QObject *o, QSettings *set);

    static QString shortcutsToString(QList <QKeySequence> shortcuts_list);
    static QList <QKeySequence> stringToShortcuts(QString shortcuts);

public slots:
	void applyChanges();
//	void saveActionsTable();
//	bool saveActionsTable(const QString & filename);
//	void loadActionsTable();
//	bool loadActionsTable(const QString & filename);

	void updateView();

protected:
	virtual void retranslateStrings();
	virtual void changeEvent ( QEvent * event ) ;

	// Find in table, not in actionslist
	int findActionName(const QString & name);
	int findActionAccel(const QString & accel, int ignoreRow = -1);
	bool hasConflicts();
	static bool containsShortcut(const QString & accel, const QString & shortcut);

protected slots:
	void editShortcut();

private:
	QTableWidget *actionsTable;
    QList<QAction*> actionsList;
//    QList<QPushButton*> btnActionsList;
//	QPushButton *saveButton;
//	QPushButton *loadButton;
	QString latest_dir;

//	QPushButton *editButton;
};

#endif