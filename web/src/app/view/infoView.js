/**
 * @name MFT.InfoView
 * 
 * @desc Info module visual representation
 * 
 * @category	Info
 * @filesource	app/view/InfoView.js
 * @version		2.0
 *
 * @author		Gerashchenko Maksym
 */
 
MFT.InfoView = Em.ContainerView.create( MFT.LoadableView, {
 	
 	elementId:	'info_view',
 	 
	/** Bind class for visual representation */
	classNameBindings: [
		'MFT.helpMode'
		//'FFW.Backend.isNavigationEnabled::green_bg'	
	],
	
	classNames:	['green_bg'],
	
	controllerBinding: Ember.Binding.oneWay('MFT.InfoController'),
		
	/** Settings components */
	childViews: [
		'leftMenu'
	],
	
	
	/** Left menu */
	leftMenu: Em.ContainerView.extend({
		elementId:	'info_leftMenu',
		
		classNameBindings:	['parentView.controller.hiddenLeftMenu:hidden'],
		
		classNames: 'menu-items',		
		
		childViews: [
			'border',
			'items'
		],
		
		border: Em.View.extend({
			classNames:	'ls_border'
		}),
		
		items: Em.ContainerView.extend({
			classNames:	'ls-items',
					
			childViews: [
				'servicesButton',
				'travelLinkButton',
				'alertsButton',
				'calendarButton',
				'appsButton',
                'whereAmIButton'
			],
		
			servicesButton: MFT.Button.extend({
				elementId:			 'info_leftMenu_services',
				goToState:   			 'services',	
				classNames:			'menu-item lsp1_p',
				classNameBindings:	 ['MFT.States.info.services.active:info_active', 'MFT.SettingsModel.isEnglish::hidden'],
				textBinding:		   'MFT.locale.label.view_info_leftmenu_services',
				icon:				  'images/info/info_leftMenu_services_ico.png',
				action:				'onState',
				target:				'MFT.InfoController'
			}),
			
			travelLinkButton: MFT.Button.extend({
				elementId:			 'info_leftMenu_travelLink',
				goToState:   			 'travelLink',	
				classNames:			'menu-item lsp1_p',
				classNameBindings:	 ['MFT.States.info.travelLink.active:info_active', 'MFT.SettingsModel.isSpanish:hidden'],
				textBinding:		   'MFT.locale.label.view_info_leftmenu_travelLink',
				icon:				  'images/info/info_leftMenu_travelLink_ico.png',
				action:				'onState',
				target:				'MFT.InfoController'
			}),
			
			alertsButton: MFT.Button.extend({
				elementId:			 'info_leftMenu_alerts',
				goToState:   			 'alerts',
				classNames:			'menu-item lsp1_p',
				classNameBindings:	 ['MFT.States.info.alerts.active:info_active'],
				textBinding:		   'MFT.locale.label.view_info_leftmenu_alerts',
				icon:				  'images/info/info_leftMenu_alerts_ico.png',
				action:				'onState',
				target:				'MFT.InfoController'
			}),
		
			calendarButton: MFT.Button.extend({
				elementId:			 'info_leftMenu_calendar',
				goToState:   			 'calendar',	
				classNames:			'menu-item lsp1_p',
				classNameBindings:	 ['MFT.States.info.calendar.active:info_active'],
				textBinding:		   'MFT.locale.label.view_info_leftmenu_calendar',
				icon:				  'images/info/info_leftMenu_calendar_ico.png',
				action:				'onState',
				target:				'MFT.InfoController'
			}),
			
			appsButton: MFT.Button.extend({
				elementId:			 'info_leftMenu_apps',
				goToState:   			 'apps',	
				classNames:			'menu-item lsp1_p',
				classNameBindings:	 ['MFT.States.info.apps.active:info_active'],
				textBinding:		   'MFT.locale.label.view_info_leftmenu_apps',
				icon:				  'images/info/info_leftMenu_apps_ico.png',
				action:				'onState',
				target:				'MFT.InfoController'
			}),

            whereAmIButton: MFT.Button.extend({
                elementId:			 'info_leftMenu_whereAmI',
                goToState:   			 'whereAmI',
                classNames:			'menu-item lsp1_p two-lines',
                classNameBindings:	 ['MFT.States.info.whereAmI.active:info_active'],
                textBinding:		   'MFT.locale.label.view_info_leftmenu_whereAmI',
                icon:				  'images/info/ico_upArrow.png',
                action:				'onState',
                target:				'MFT.InfoController'
            })
		})
	})		
});