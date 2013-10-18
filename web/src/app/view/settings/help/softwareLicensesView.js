/**
 * @name MFT.SettingsHelpSoftwareLicensesView
 * 
 * @desc Settings Help Software Licenses module visual representation
 * 
 * @category	View
 * @filesource	app/view/settings/SettingsHelpSoftwareLicensesView.js
 * @version		2.0
 *
 * @author		Maksym Gerashchenko
 */

MFT.SettingsHelpSoftwareLicensesView = Em.ContainerView.create(MFT.LoadableView,{
    dataListBinding: 'MFT.SettingsData.clocklist',
    elementId: 'settings_help_softwareLicenses',
    classNames: 'settings-list-block',

    childViews: [
        'backButton',
        'topTitile',
        'listTitles',
        'installUpdatesButton',
        'list'
    ],
	backButton: MFT.Button.extend({
        elementId: 			'settings_help_softwareLicenses_backButton',
        classNames:		  ['backButton','button'],
        action:			  'back',
        target:			  'MFT.States',
        icon:				'images/media/ico_back.png'
	}),
	
	topTitile: MFT.Label.extend({
		elementId:		   'settings_help_softwareLicenses_titile',
		classNames:		  ['block-header-title'],
		contentBinding:	  'MFT.locale.label.view_settings_help_softwareLicenses_titile'
	}),
	
	listTitles: Em.ContainerView.extend({
		classNames:		  ['list-titles'],
		childViews:		   [
							  'titleName',
							  'titleData',
							  'titleUsers',
						  ],
		titleName:	MFT.Label.extend({
			classNames:		  ['title-name'],
			contentBinding:	  'MFT.locale.label.view_settings_help_softwareLicenses_applicationName'
		}),
		titleData:MFT.Label.extend({
            classNames:		  ['title-data'],
			contentBinding:	  'MFT.locale.label.view_settings_help_softwareLicenses_expirationDate'
		}),
		titleUsers:MFT.Label.extend({
            classNames:		  ['title-users'],
			contentBinding:	  'MFT.locale.label.view_settings_help_softwareLicenses_remainingUses'
		})
	}),
	
	installUpdatesButton: MFT.Button.extend({
		textBinding:	  'MFT.locale.label.view_settings_help_softwareLicenses_install',
		classNames:		  [,'button'],
		elementId:	       'installUpdatesButton',
		goToState:	       'settings.system.installApplications',
		action:			  'onState',
		target:			  'MFT.SettingsController',
		onDown: false,
		helpMode: true
	}),
					  
	
	list:	MFT.List.extend({
			
			elementId:	  'settings_help_softwareLicenses_list',
			
			itemsOnPage:	 5,
			
			disableScrollbar:	false,
				
			items:[
			{
								
				type:		 MFT.TableLabel,
				params:		{
					icon:		   			'images/settings/ico_LED.png',
					rightIcon:      		   'images/settings/smll-ar-r.png',
					contentBinding:	  	  'MFT.locale.label.view_settings_help_softwareLicenses_navigation',
					contentSecondBinding:	'MFT.locale.label.view_settings_help_softwareLicenses_none',
					contentThirdBinding:	 'MFT.locale.label.view_settings_help_softwareLicenses_unlimited',
				}			
					
			}
		]
	})
});